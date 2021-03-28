// MIT License
//
// Copyright (c) 2021 Adrien Vasseur
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

#include "system/memory/StackAllocator.hpp"

namespace ng
{
  namespace system
  {
    StackAllocator::StackAllocator(std::uint64_t pageSize) :
      _pageSize(pageSize),
      _pageHeaderSize(ALIGN(sizeof(t_stack_page), DEFAULT_ALIGN_SIZE)),
      _slotHeaderSize(ALIGN(sizeof(t_stack_slot), DEFAULT_ALIGN_SIZE))
    {
      _currentPage = reinterpret_cast<t_stack_page *>(_systemAlloc(_pageSize));
      _currentPage->last = nullptr;
      _currentPage->next = nullptr;
      _currentPage->size = _pageSize;
      _currentPage->top = reinterpret_cast<t_stack_slot *>(((
        reinterpret_cast<char *>(_currentPage)) +
        ALIGN(sizeof(t_stack_page), DEFAULT_ALIGN_SIZE)));
      _currentPage->top->last = nullptr;
      _currentPage->top->free = true;
    }

    StackAllocator::~StackAllocator()
    {
      t_stack_page *page;

      /*if (_currentPage->last != nullptr ||
          _currentPage->top->last != nullptr)
        WARN("StackAllocator: Memory leak detected!");*/
      page = _currentPage->last;
      _systemFree(_currentPage);
      while (page)
      {
        _currentPage = page;
        page = _currentPage->last;
        _systemFree(_currentPage);
      }
    }

    void *StackAllocator::allocate(std::uint64_t const size)
    {
      std::uint64_t slotSize = ALIGN(size, DEFAULT_ALIGN_SIZE) +
        _slotHeaderSize;
      void *ptr;

      if ((reinterpret_cast<char *>(_currentPage->top)) +
        slotSize + _slotHeaderSize >=
        (reinterpret_cast<char *>(_currentPage)) +
        _currentPage->size)
        _pageAlloc(slotSize);
      ptr = _slotAlloc(slotSize);
      return (ptr);
    }

    void StackAllocator::free(void *ptr)
    {
      t_stack_slot *slot = reinterpret_cast<t_stack_slot *>((
        reinterpret_cast<char *>(ptr)) - _slotHeaderSize);

      slot->free = true;
      if (_currentPage->top->last == slot)
        _slotFree(slot);
    }

    void *StackAllocator::_systemAlloc(std::uint64_t const size)
    {
      return (std::malloc(size));
    }

    void StackAllocator::_systemFree(void *ptr)
    {
      std::free(ptr);
    }

    void StackAllocator::_pageAlloc(std::uint64_t const size)
    {
      std::uint64_t pageSize = ALIGN(size + _pageHeaderSize, _pageSize);
      t_stack_page *page = reinterpret_cast<t_stack_page *>(
        _systemAlloc(pageSize));

      if (page == nullptr)
        throw std::bad_alloc();
      _currentPage->next = page;
      page->last = _currentPage;
      page->next = nullptr;
      page->size = pageSize;
      page->top = reinterpret_cast<t_stack_slot *>(((
        reinterpret_cast<char *>(_currentPage)) +
        ALIGN(sizeof(t_stack_page), DEFAULT_ALIGN_SIZE)));
      page->top->last = nullptr;
      page->top->free = true;
      _currentPage = page;
    }

    void StackAllocator::_pageFree()
    {
      t_stack_page *page = _currentPage;

      if (page->last != nullptr)
      {
        _currentPage = page->last;
        _systemFree(page);
      }
    }

    void *StackAllocator::_slotAlloc(std::uint64_t const size)
    {
      t_stack_slot *slot;
      void *ptr;

      slot = _currentPage->top;
      slot->free = false;
      ptr = (reinterpret_cast<char *>(slot)) + _slotHeaderSize;
      _currentPage->top = reinterpret_cast<t_stack_slot *>(((
        reinterpret_cast<char *>(slot)) + size));
      _currentPage->top->last = slot;
      _currentPage->top->free = true;
      return (ptr);
    }

    void StackAllocator::_slotFree(t_stack_slot *top)
    {
      _currentPage->top = top;
      while (_currentPage->top->last != nullptr &&
        _currentPage->top->free)
      {
        _currentPage->top = _currentPage->top->last;
        if (_currentPage->top->last == nullptr &&
          _currentPage->top->free)
        _pageFree();
      }
    }
  } // namespace system
} // namespace ng
