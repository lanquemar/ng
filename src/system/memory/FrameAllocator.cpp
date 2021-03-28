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

#include <algorithm>

#include "system/memory/FrameAllocator.hpp"

namespace ng
{
  namespace system
  {
    FrameAllocator::FrameAllocator(std::uint64_t pageSize,
      std::uint64_t slotSize) :
      _headerPageSize(ALIGN(sizeof(t_frame_page), DEFAULT_ALIGN_SIZE)),
      _headerSlotSize(ALIGN(sizeof(t_frame_slot), DEFAULT_ALIGN_SIZE)),
      _slotSize(std::max(ALIGN(slotSize, DEFAULT_ALIGN_SIZE), _headerSlotSize)),
      _pageSize(ALIGN(pageSize, DEFAULT_ALIGN_SIZE))
    {
      _currentPage =
        reinterpret_cast<t_frame_page *>(
          _systemAlloc(_pageSize));
      _currentPage->next = nullptr;
      _currentSlot =
        reinterpret_cast<t_frame_slot *>((
          (reinterpret_cast<char *>(_currentPage)) + _headerPageSize));
      _currentSlot->size = (_pageSize - _headerPageSize) / _slotSize;
      _currentSlot->next = nullptr;
    }

    FrameAllocator::~FrameAllocator()
    {
      t_frame_page *page;

      while (_currentPage)
      {
        page = _currentPage->next;
        _systemFree(_currentPage);
        _currentPage = page;
      }
    }

    void *FrameAllocator::allocate(std::uint64_t const size)
    {
      void *ptr = nullptr;

      if (size > _slotSize)
      {
        //ERROR("FrameAllocator: A frame of " << size << " bytes has been asked;
        //max frame size available: " << _slotSize << " bytes.");
        throw std::bad_alloc();
      }
      if (!_currentSlot)
        _pageAlloc();
      ptr = _slotAlloc();
      return (ptr);
    }

    void FrameAllocator::free(void *ptr)
    {
      t_frame_slot *slot;

      slot = reinterpret_cast<t_frame_slot *>(ptr);
      slot->size = 1;
      slot->next = _currentSlot;
      _currentSlot = slot;
    }

    void *FrameAllocator::_systemAlloc(std::uint64_t const size)
    {
      return (std::malloc(size));
    }

    void FrameAllocator::_systemFree(void *ptr)
    {
      std::free(ptr);
    }

    void FrameAllocator::_pageAlloc()
    {
      t_frame_page *page;

      page = reinterpret_cast<t_frame_page *>(
        _systemAlloc(_pageSize));
      page->next = _currentPage;
      _currentPage = page;
      _currentSlot =
        reinterpret_cast<t_frame_slot *>(((
          reinterpret_cast<char *>(_currentPage))
          + _headerPageSize));
      _currentSlot->size =
        (_pageSize - _headerPageSize) / _slotSize;
      _currentSlot->next = nullptr;
    }

    void *FrameAllocator::_slotAlloc()
    {
      t_frame_slot *current;
      t_frame_slot *next;

      current = _currentSlot;
      if (current->size > 1)
      {
        next = reinterpret_cast<t_frame_slot *>(((
          reinterpret_cast<char *>(current)) + _slotSize));
        next->size = current->size - 1;
        next->next = current->next;
        _currentSlot = next;
      } else {
        _currentSlot = current->next;
      }
      return (reinterpret_cast<void *>(current));
    }
  } // namespace system
} // namespace ng
