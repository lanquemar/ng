#include "GLFWKeyboard.hpp"

#include "graphics/Keyboard.hpp"

namespace ng
{
  namespace graphics
  {
    namespace impl
    {
      const std::size_t GLFWKeyboard::glfwToNgSize = GLFW_KEY_LAST + 1;
      const ng::graphics::Keyboard::Key GLFWKeyboard::glfwToNg[glfwToNgSize] = {
        ng::graphics::Keyboard::UNKNOWN,       // 0
        ng::graphics::Keyboard::UNKNOWN,       // 1
        ng::graphics::Keyboard::UNKNOWN,       // 2
        ng::graphics::Keyboard::UNKNOWN,       // 3
        ng::graphics::Keyboard::UNKNOWN,       // 4
        ng::graphics::Keyboard::UNKNOWN,       // 5
        ng::graphics::Keyboard::UNKNOWN,       // 6
        ng::graphics::Keyboard::UNKNOWN,       // 7
        ng::graphics::Keyboard::UNKNOWN,       // 8
        ng::graphics::Keyboard::UNKNOWN,       // 9
        ng::graphics::Keyboard::UNKNOWN,       // 10
        ng::graphics::Keyboard::UNKNOWN,       // 11
        ng::graphics::Keyboard::UNKNOWN,       // 12
        ng::graphics::Keyboard::UNKNOWN,       // 13
        ng::graphics::Keyboard::UNKNOWN,       // 14
        ng::graphics::Keyboard::UNKNOWN,       // 15
        ng::graphics::Keyboard::UNKNOWN,       // 16
        ng::graphics::Keyboard::UNKNOWN,       // 17
        ng::graphics::Keyboard::UNKNOWN,       // 18
        ng::graphics::Keyboard::UNKNOWN,       // 19
        ng::graphics::Keyboard::UNKNOWN,       // 20
        ng::graphics::Keyboard::UNKNOWN,       // 21
        ng::graphics::Keyboard::UNKNOWN,       // 22
        ng::graphics::Keyboard::UNKNOWN,       // 23
        ng::graphics::Keyboard::UNKNOWN,       // 24
        ng::graphics::Keyboard::UNKNOWN,       // 25
        ng::graphics::Keyboard::UNKNOWN,       // 26
        ng::graphics::Keyboard::UNKNOWN,       // 27
        ng::graphics::Keyboard::UNKNOWN,       // 28
        ng::graphics::Keyboard::UNKNOWN,       // 29
        ng::graphics::Keyboard::UNKNOWN,       // 30
        ng::graphics::Keyboard::UNKNOWN,       // 31
        ng::graphics::Keyboard::SPACE,         // 32 GLFW_KEY_SPACE
        ng::graphics::Keyboard::UNKNOWN,       // 33
        ng::graphics::Keyboard::UNKNOWN,       // 34
        ng::graphics::Keyboard::UNKNOWN,       // 35
        ng::graphics::Keyboard::UNKNOWN,       // 36
        ng::graphics::Keyboard::UNKNOWN,       // 37
        ng::graphics::Keyboard::UNKNOWN,       // 38
        ng::graphics::Keyboard::APOSTROPHE,    // 39 GLFW_KEY_APOSTROPHE
        ng::graphics::Keyboard::UNKNOWN,       // 40
        ng::graphics::Keyboard::UNKNOWN,       // 41
        ng::graphics::Keyboard::UNKNOWN,       // 42
        ng::graphics::Keyboard::UNKNOWN,       // 43
        ng::graphics::Keyboard::COMMA,         // 44 GLFW_KEY_COMMA
        ng::graphics::Keyboard::MINUS,         // 45 GLFW_KEY_MINUS
        ng::graphics::Keyboard::PERIOD,        // 46 GLFW_KEY_PERIOD
        ng::graphics::Keyboard::SLASH,         // 47 GLFW_KEY_SLASH
        ng::graphics::Keyboard::NUM_0,         // 48 GLFW_KEY_0
        ng::graphics::Keyboard::NUM_1,         // 49 GLFW_KEY_1
        ng::graphics::Keyboard::NUM_2,         // 50 GLFW_KEY_2
        ng::graphics::Keyboard::NUM_3,         // 51 GLFW_KEY_3
        ng::graphics::Keyboard::NUM_4,         // 52 GLFW_KEY_4
        ng::graphics::Keyboard::NUM_5,         // 53 GLFW_KEY_5
        ng::graphics::Keyboard::NUM_6,         // 54 GLFW_KEY_6
        ng::graphics::Keyboard::NUM_7,         // 55 GLFW_KEY_7
        ng::graphics::Keyboard::NUM_8,         // 56 GLFW_KEY_8
        ng::graphics::Keyboard::NUM_9,         // 57 GLFW_KEY_9
        ng::graphics::Keyboard::UNKNOWN,       // 58
        ng::graphics::Keyboard::SEMICOLON,     // 59 GLFW_KEY_SEMICOLON
        ng::graphics::Keyboard::UNKNOWN,       // 60
        ng::graphics::Keyboard::EQUAL,         // 61 GLFW_KEY_EQUAL
        ng::graphics::Keyboard::UNKNOWN,       // 62
        ng::graphics::Keyboard::UNKNOWN,       // 63
        ng::graphics::Keyboard::UNKNOWN,       // 64
        ng::graphics::Keyboard::A,             // 65 GLFW_KEY_A
        ng::graphics::Keyboard::B,             // 66 GLFW_KEY_B
        ng::graphics::Keyboard::C,             // 67 GLFW_KEY_C
        ng::graphics::Keyboard::D,             // 68 GLFW_KEY_D
        ng::graphics::Keyboard::E,             // 69 GLFW_KEY_E
        ng::graphics::Keyboard::F,             // 70 GLFW_KEY_F
        ng::graphics::Keyboard::G,             // 71 GLFW_KEY_G
        ng::graphics::Keyboard::H,             // 72 GLFW_KEY_H
        ng::graphics::Keyboard::I,             // 73 GLFW_KEY_I
        ng::graphics::Keyboard::J,             // 74 GLFW_KEY_J
        ng::graphics::Keyboard::K,             // 75 GLFW_KEY_K
        ng::graphics::Keyboard::L,             // 76 GLFW_KEY_L
        ng::graphics::Keyboard::M,             // 77 GLFW_KEY_M
        ng::graphics::Keyboard::N,             // 78 GLFW_KEY_N
        ng::graphics::Keyboard::O,             // 79 GLFW_KEY_O
        ng::graphics::Keyboard::P,             // 80 GLFW_KEY_P
        ng::graphics::Keyboard::Q,             // 81 GLFW_KEY_Q
        ng::graphics::Keyboard::R,             // 82 GLFW_KEY_R
        ng::graphics::Keyboard::S,             // 83 GLFW_KEY_S
        ng::graphics::Keyboard::T,             // 84 GLFW_KEY_T
        ng::graphics::Keyboard::U,             // 85 GLFW_KEY_U
        ng::graphics::Keyboard::V,             // 86 GLFW_KEY_V
        ng::graphics::Keyboard::W,             // 87 GLFW_KEY_W
        ng::graphics::Keyboard::X,             // 88 GLFW_KEY_X
        ng::graphics::Keyboard::Y,             // 89 GLFW_KEY_Y
        ng::graphics::Keyboard::Z,             // 90 GLFW_KEY_Z
        ng::graphics::Keyboard::LEFT_BRACKET,  // 91 GLFW_KEY_LEFT_BRACKET
        ng::graphics::Keyboard::BACKSLASH,     // 92 GLFW_KEY_BACKSLASH
        ng::graphics::Keyboard::RIGHT_BRACKET, // 93 GLFW_KEY_RIGHT_BRACKET
        ng::graphics::Keyboard::UNKNOWN,       // 94
        ng::graphics::Keyboard::UNKNOWN,       // 95
        ng::graphics::Keyboard::GRAVE_ACCENT,  // 96 GLFW_KEY_GRAVE_ACCENT
        ng::graphics::Keyboard::UNKNOWN,       // 97
        ng::graphics::Keyboard::UNKNOWN,       // 98
        ng::graphics::Keyboard::UNKNOWN,       // 99
        ng::graphics::Keyboard::UNKNOWN,       // 100
        ng::graphics::Keyboard::UNKNOWN,       // 101
        ng::graphics::Keyboard::UNKNOWN,       // 102
        ng::graphics::Keyboard::UNKNOWN,       // 103
        ng::graphics::Keyboard::UNKNOWN,       // 104
        ng::graphics::Keyboard::UNKNOWN,       // 105
        ng::graphics::Keyboard::UNKNOWN,       // 106
        ng::graphics::Keyboard::UNKNOWN,       // 107
        ng::graphics::Keyboard::UNKNOWN,       // 108
        ng::graphics::Keyboard::UNKNOWN,       // 109
        ng::graphics::Keyboard::UNKNOWN,       // 110
        ng::graphics::Keyboard::UNKNOWN,       // 111
        ng::graphics::Keyboard::UNKNOWN,       // 112
        ng::graphics::Keyboard::UNKNOWN,       // 113
        ng::graphics::Keyboard::UNKNOWN,       // 114
        ng::graphics::Keyboard::UNKNOWN,       // 115
        ng::graphics::Keyboard::UNKNOWN,       // 116
        ng::graphics::Keyboard::UNKNOWN,       // 117
        ng::graphics::Keyboard::UNKNOWN,       // 118
        ng::graphics::Keyboard::UNKNOWN,       // 119
        ng::graphics::Keyboard::UNKNOWN,       // 120
        ng::graphics::Keyboard::UNKNOWN,       // 121
        ng::graphics::Keyboard::UNKNOWN,       // 122
        ng::graphics::Keyboard::UNKNOWN,       // 123
        ng::graphics::Keyboard::UNKNOWN,       // 124
        ng::graphics::Keyboard::UNKNOWN,       // 125
        ng::graphics::Keyboard::UNKNOWN,       // 126
        ng::graphics::Keyboard::UNKNOWN,       // 127
        ng::graphics::Keyboard::UNKNOWN,       // 128
        ng::graphics::Keyboard::UNKNOWN,       // 129
        ng::graphics::Keyboard::UNKNOWN,       // 130
        ng::graphics::Keyboard::UNKNOWN,       // 131
        ng::graphics::Keyboard::UNKNOWN,       // 132
        ng::graphics::Keyboard::UNKNOWN,       // 133
        ng::graphics::Keyboard::UNKNOWN,       // 134
        ng::graphics::Keyboard::UNKNOWN,       // 135
        ng::graphics::Keyboard::UNKNOWN,       // 136
        ng::graphics::Keyboard::UNKNOWN,       // 137
        ng::graphics::Keyboard::UNKNOWN,       // 138
        ng::graphics::Keyboard::UNKNOWN,       // 139
        ng::graphics::Keyboard::UNKNOWN,       // 140
        ng::graphics::Keyboard::UNKNOWN,       // 141
        ng::graphics::Keyboard::UNKNOWN,       // 142
        ng::graphics::Keyboard::UNKNOWN,       // 143
        ng::graphics::Keyboard::UNKNOWN,       // 144
        ng::graphics::Keyboard::UNKNOWN,       // 145
        ng::graphics::Keyboard::UNKNOWN,       // 146
        ng::graphics::Keyboard::UNKNOWN,       // 147
        ng::graphics::Keyboard::UNKNOWN,       // 148
        ng::graphics::Keyboard::UNKNOWN,       // 149
        ng::graphics::Keyboard::UNKNOWN,       // 150
        ng::graphics::Keyboard::UNKNOWN,       // 151
        ng::graphics::Keyboard::UNKNOWN,       // 152
        ng::graphics::Keyboard::UNKNOWN,       // 153
        ng::graphics::Keyboard::UNKNOWN,       // 154
        ng::graphics::Keyboard::UNKNOWN,       // 155
        ng::graphics::Keyboard::UNKNOWN,       // 156
        ng::graphics::Keyboard::UNKNOWN,       // 157
        ng::graphics::Keyboard::UNKNOWN,       // 158
        ng::graphics::Keyboard::UNKNOWN,       // 159
        ng::graphics::Keyboard::UNKNOWN,       // 160
        ng::graphics::Keyboard::UNKNOWN,       // 161 GLFW_KEY_WORLD_1
        ng::graphics::Keyboard::UNKNOWN,       // 162 GLFW_KEY_WORLD_2
        ng::graphics::Keyboard::UNKNOWN,       // 163
        ng::graphics::Keyboard::UNKNOWN,       // 164
        ng::graphics::Keyboard::UNKNOWN,       // 165
        ng::graphics::Keyboard::UNKNOWN,       // 166
        ng::graphics::Keyboard::UNKNOWN,       // 167
        ng::graphics::Keyboard::UNKNOWN,       // 168
        ng::graphics::Keyboard::UNKNOWN,       // 169
        ng::graphics::Keyboard::UNKNOWN,       // 170
        ng::graphics::Keyboard::UNKNOWN,       // 171
        ng::graphics::Keyboard::UNKNOWN,       // 172
        ng::graphics::Keyboard::UNKNOWN,       // 173
        ng::graphics::Keyboard::UNKNOWN,       // 174
        ng::graphics::Keyboard::UNKNOWN,       // 175
        ng::graphics::Keyboard::UNKNOWN,       // 176
        ng::graphics::Keyboard::UNKNOWN,       // 177
        ng::graphics::Keyboard::UNKNOWN,       // 178
        ng::graphics::Keyboard::UNKNOWN,       // 179
        ng::graphics::Keyboard::UNKNOWN,       // 180
        ng::graphics::Keyboard::UNKNOWN,       // 181
        ng::graphics::Keyboard::UNKNOWN,       // 182
        ng::graphics::Keyboard::UNKNOWN,       // 183
        ng::graphics::Keyboard::UNKNOWN,       // 184
        ng::graphics::Keyboard::UNKNOWN,       // 185
        ng::graphics::Keyboard::UNKNOWN,       // 186
        ng::graphics::Keyboard::UNKNOWN,       // 187
        ng::graphics::Keyboard::UNKNOWN,       // 188
        ng::graphics::Keyboard::UNKNOWN,       // 189
        ng::graphics::Keyboard::UNKNOWN,       // 190
        ng::graphics::Keyboard::UNKNOWN,       // 191
        ng::graphics::Keyboard::UNKNOWN,       // 192
        ng::graphics::Keyboard::UNKNOWN,       // 193
        ng::graphics::Keyboard::UNKNOWN,       // 194
        ng::graphics::Keyboard::UNKNOWN,       // 195
        ng::graphics::Keyboard::UNKNOWN,       // 196
        ng::graphics::Keyboard::UNKNOWN,       // 197
        ng::graphics::Keyboard::UNKNOWN,       // 198
        ng::graphics::Keyboard::UNKNOWN,       // 199
        ng::graphics::Keyboard::UNKNOWN,       // 200
        ng::graphics::Keyboard::UNKNOWN,       // 201
        ng::graphics::Keyboard::UNKNOWN,       // 202
        ng::graphics::Keyboard::UNKNOWN,       // 203
        ng::graphics::Keyboard::UNKNOWN,       // 204
        ng::graphics::Keyboard::UNKNOWN,       // 205
        ng::graphics::Keyboard::UNKNOWN,       // 206
        ng::graphics::Keyboard::UNKNOWN,       // 207
        ng::graphics::Keyboard::UNKNOWN,       // 208
        ng::graphics::Keyboard::UNKNOWN,       // 209
        ng::graphics::Keyboard::UNKNOWN,       // 210
        ng::graphics::Keyboard::UNKNOWN,       // 211
        ng::graphics::Keyboard::UNKNOWN,       // 212
        ng::graphics::Keyboard::UNKNOWN,       // 213
        ng::graphics::Keyboard::UNKNOWN,       // 214
        ng::graphics::Keyboard::UNKNOWN,       // 215
        ng::graphics::Keyboard::UNKNOWN,       // 216
        ng::graphics::Keyboard::UNKNOWN,       // 217
        ng::graphics::Keyboard::UNKNOWN,       // 218
        ng::graphics::Keyboard::UNKNOWN,       // 219
        ng::graphics::Keyboard::UNKNOWN,       // 220
        ng::graphics::Keyboard::UNKNOWN,       // 221
        ng::graphics::Keyboard::UNKNOWN,       // 222
        ng::graphics::Keyboard::UNKNOWN,       // 223
        ng::graphics::Keyboard::UNKNOWN,       // 224
        ng::graphics::Keyboard::UNKNOWN,       // 225
        ng::graphics::Keyboard::UNKNOWN,       // 226
        ng::graphics::Keyboard::UNKNOWN,       // 227
        ng::graphics::Keyboard::UNKNOWN,       // 228
        ng::graphics::Keyboard::UNKNOWN,       // 229
        ng::graphics::Keyboard::UNKNOWN,       // 230
        ng::graphics::Keyboard::UNKNOWN,       // 231
        ng::graphics::Keyboard::UNKNOWN,       // 232
        ng::graphics::Keyboard::UNKNOWN,       // 233
        ng::graphics::Keyboard::UNKNOWN,       // 234
        ng::graphics::Keyboard::UNKNOWN,       // 235
        ng::graphics::Keyboard::UNKNOWN,       // 236
        ng::graphics::Keyboard::UNKNOWN,       // 237
        ng::graphics::Keyboard::UNKNOWN,       // 238
        ng::graphics::Keyboard::UNKNOWN,       // 239
        ng::graphics::Keyboard::UNKNOWN,       // 240
        ng::graphics::Keyboard::UNKNOWN,       // 241
        ng::graphics::Keyboard::UNKNOWN,       // 242
        ng::graphics::Keyboard::UNKNOWN,       // 243
        ng::graphics::Keyboard::UNKNOWN,       // 244
        ng::graphics::Keyboard::UNKNOWN,       // 245
        ng::graphics::Keyboard::UNKNOWN,       // 246
        ng::graphics::Keyboard::UNKNOWN,       // 247
        ng::graphics::Keyboard::UNKNOWN,       // 248
        ng::graphics::Keyboard::UNKNOWN,       // 249
        ng::graphics::Keyboard::UNKNOWN,       // 250
        ng::graphics::Keyboard::UNKNOWN,       // 251
        ng::graphics::Keyboard::UNKNOWN,       // 252
        ng::graphics::Keyboard::UNKNOWN,       // 253
        ng::graphics::Keyboard::UNKNOWN,       // 254
        ng::graphics::Keyboard::UNKNOWN,       // 255
        ng::graphics::Keyboard::ESCAPE,        // 256 GLFW_KEY_ESCAPE
        ng::graphics::Keyboard::ENTER,         // 257 GLFW_KEY_ENTER
        ng::graphics::Keyboard::TAB,           // 258 GLFW_KEY_TAB
        ng::graphics::Keyboard::BACKSPACE,     // 259 GLFW_KEY_BACKSPACE
        ng::graphics::Keyboard::INSERT,        // 260 GLFW_KEY_INSERT
        ng::graphics::Keyboard::DELETE,        // 261 GLFW_KEY_DELETE
        ng::graphics::Keyboard::RIGHT,         // 262 GLFW_KEY_RIGHT
        ng::graphics::Keyboard::LEFT,          // 263 GLFW_KEY_LEFT
        ng::graphics::Keyboard::DOWN,          // 264 GLFW_KEY_DOWN
        ng::graphics::Keyboard::UP,            // 265 GLFW_KEY_UP
        ng::graphics::Keyboard::PAGE_UP,       // 266 GLFW_KEY_PAGE_UP
        ng::graphics::Keyboard::PAGE_DOWN,     // 267 GLFW_KEY_PAGE_DOWN
        ng::graphics::Keyboard::HOME,          // 268 GLFW_KEY_HOME
        ng::graphics::Keyboard::END,           // 269 GLFW_KEY_END
        ng::graphics::Keyboard::UNKNOWN,       // 270
        ng::graphics::Keyboard::UNKNOWN,       // 271
        ng::graphics::Keyboard::UNKNOWN,       // 272
        ng::graphics::Keyboard::UNKNOWN,       // 273
        ng::graphics::Keyboard::UNKNOWN,       // 274
        ng::graphics::Keyboard::UNKNOWN,       // 275
        ng::graphics::Keyboard::UNKNOWN,       // 276
        ng::graphics::Keyboard::UNKNOWN,       // 277
        ng::graphics::Keyboard::UNKNOWN,       // 278
        ng::graphics::Keyboard::UNKNOWN,       // 279
        ng::graphics::Keyboard::CAPS_LOCK,     // 280 GLFW_KEY_CAPS_LOCK
        ng::graphics::Keyboard::SCROLL_LOCK,   // 281 GLFW_KEY_SCROLL_LOCK
        ng::graphics::Keyboard::NUM_LOCK,      // 282 GLFW_KEY_NUM_LOCK
        ng::graphics::Keyboard::PRINT_SCREEN,  // 283 GLFW_KEY_PRINT_SCREEN
        ng::graphics::Keyboard::PAUSE,         // 284 GLFW_KEY_PAUSE
        ng::graphics::Keyboard::UNKNOWN,       // 285
        ng::graphics::Keyboard::UNKNOWN,       // 286
        ng::graphics::Keyboard::UNKNOWN,       // 287
        ng::graphics::Keyboard::UNKNOWN,       // 288
        ng::graphics::Keyboard::UNKNOWN,       // 289
        ng::graphics::Keyboard::F1,            // 290 GLFW_KEY_F1
        ng::graphics::Keyboard::F2,            // 291 GLFW_KEY_F2
        ng::graphics::Keyboard::F3,            // 292 GLFW_KEY_F3
        ng::graphics::Keyboard::F4,            // 293 GLFW_KEY_F4
        ng::graphics::Keyboard::F5,            // 294 GLFW_KEY_F5
        ng::graphics::Keyboard::F6,            // 295 GLFW_KEY_F6
        ng::graphics::Keyboard::F7,            // 296 GLFW_KEY_F7
        ng::graphics::Keyboard::F8,            // 297 GLFW_KEY_F8
        ng::graphics::Keyboard::F9,            // 298 GLFW_KEY_F9
        ng::graphics::Keyboard::F10,           // 299 GLFW_KEY_F10
        ng::graphics::Keyboard::F11,           // 300 GLFW_KEY_F11
        ng::graphics::Keyboard::F12,           // 301 GLFW_KEY_F12
        ng::graphics::Keyboard::F13,           // 302 GLFW_KEY_F13
        ng::graphics::Keyboard::F14,           // 303 GLFW_KEY_F14
        ng::graphics::Keyboard::F15,           // 304 GLFW_KEY_F15
        ng::graphics::Keyboard::F16,           // 305 GLFW_KEY_F16
        ng::graphics::Keyboard::F17,           // 306 GLFW_KEY_F17
        ng::graphics::Keyboard::F18,           // 307 GLFW_KEY_F18
        ng::graphics::Keyboard::F19,           // 308 GLFW_KEY_F19
        ng::graphics::Keyboard::F20,           // 309 GLFW_KEY_F20
        ng::graphics::Keyboard::F21,           // 310 GLFW_KEY_F21
        ng::graphics::Keyboard::F22,           // 311 GLFW_KEY_F22
        ng::graphics::Keyboard::F23,           // 312 GLFW_KEY_F23
        ng::graphics::Keyboard::F24,           // 313 GLFW_KEY_F24
        ng::graphics::Keyboard::F25,           // 314 GLFW_KEY_F25
        ng::graphics::Keyboard::UNKNOWN,       // 315
        ng::graphics::Keyboard::UNKNOWN,       // 316
        ng::graphics::Keyboard::UNKNOWN,       // 317
        ng::graphics::Keyboard::UNKNOWN,       // 318
        ng::graphics::Keyboard::UNKNOWN,       // 319
        ng::graphics::Keyboard::NUMPAD_0,      // 320 GLFW_KEY_KP_0
        ng::graphics::Keyboard::NUMPAD_1,      // 321 GLFW_KEY_KP_1
        ng::graphics::Keyboard::NUMPAD_2,      // 322 GLFW_KEY_KP_2
        ng::graphics::Keyboard::NUMPAD_3,      // 323 GLFW_KEY_KP_3
        ng::graphics::Keyboard::NUMPAD_4,      // 324 GLFW_KEY_KP_4
        ng::graphics::Keyboard::NUMPAD_5,      // 325 GLFW_KEY_KP_5
        ng::graphics::Keyboard::NUMPAD_6,      // 326 GLFW_KEY_KP_6
        ng::graphics::Keyboard::NUMPAD_7,      // 327 GLFW_KEY_KP_7
        ng::graphics::Keyboard::NUMPAD_8,      // 328 GLFW_KEY_KP_8
        ng::graphics::Keyboard::NUMPAD_9,      // 329 GLFW_KEY_KP_9
        ng::graphics::Keyboard::DECIMAL,       // 330 GLFW_KEY_KP_DECIMAL
        ng::graphics::Keyboard::DIVIDE,        // 331 GLFW_KEY_KP_DIVIDE
        ng::graphics::Keyboard::MULTIPLY,      // 332 GLFW_KEY_KP_MULTIPLY
        ng::graphics::Keyboard::SUBSTRACT,     // 333 GLFW_KEY_KP_SUBTRACT
        ng::graphics::Keyboard::ADD,           // 334 GLFW_KEY_KP_ADD
        ng::graphics::Keyboard::ENTER,         // 335 GLFW_KEY_KP_ENTER
        ng::graphics::Keyboard::EQUAL,         // 336 GLFW_KEY_KP_EQUAL
        ng::graphics::Keyboard::UNKNOWN,       // 337
        ng::graphics::Keyboard::UNKNOWN,       // 338
        ng::graphics::Keyboard::UNKNOWN,       // 339
        ng::graphics::Keyboard::LEFT_SHIFT,    // 340 GLFW_KEY_LEFT_SHIFT
        ng::graphics::Keyboard::LEFT_CONTROL,  // 341 GLFW_KEY_LEFT_CONTROL
        ng::graphics::Keyboard::LEFT_ALT,      // 342 GLFW_KEY_LEFT_ALT
        ng::graphics::Keyboard::LEFT_SYSTEM,   // 343 GLFW_KEY_LEFT_SUPER
        ng::graphics::Keyboard::RIGHT_SHIFT,   // 344 GLFW_KEY_RIGHT_SHIFT
        ng::graphics::Keyboard::RIGHT_CONTROL, // 345 GLFW_KEY_RIGHT_CONTROL
        ng::graphics::Keyboard::RIGHT_ALT,     // 346 GLFW_KEY_RIGHT_ALT
        ng::graphics::Keyboard::RIGHT_SYSTEM,  // 347 GLFW_KEY_RIGHT_SUPER
        ng::graphics::Keyboard::MENU           // 348 GLFW_KEY_MENU
      };

      const std::size_t GLFWKeyboard::ngToGlfwSize = ng::graphics::Keyboard::MENU + 1;
      const int GLFWKeyboard::ngToGlfw[ngToGlfwSize] = {
        GLFW_KEY_A,             // 0 A
        GLFW_KEY_B,             // 1 B
        GLFW_KEY_C,             // 2 C
        GLFW_KEY_D,             // 3 D
        GLFW_KEY_E,             // 4 E
        GLFW_KEY_F,             // 5 F
        GLFW_KEY_G,             // 6 G
        GLFW_KEY_H,             // 7 H
        GLFW_KEY_I,             // 8 I
        GLFW_KEY_J,             // 9 J
        GLFW_KEY_K,             // 10 K
        GLFW_KEY_L,             // 11 L
        GLFW_KEY_M,             // 12 M
        GLFW_KEY_N,             // 13 N
        GLFW_KEY_O,             // 14 O
        GLFW_KEY_P,             // 15 P
        GLFW_KEY_Q,             // 16 Q
        GLFW_KEY_R,             // 17 R
        GLFW_KEY_S,             // 18 S
        GLFW_KEY_T,             // 19 T
        GLFW_KEY_U,             // 20 U
        GLFW_KEY_V,             // 21 V
        GLFW_KEY_W,             // 22 W
        GLFW_KEY_X,             // 23 X
        GLFW_KEY_Y,             // 24 Y
        GLFW_KEY_Z,             // 25 Z
        GLFW_KEY_0,             // 26 NUM_0
        GLFW_KEY_1,             // 27 NUM_1
        GLFW_KEY_2,             // 28 NUM_2
        GLFW_KEY_3,             // 29 NUM_3
        GLFW_KEY_4,             // 30 NUM_4
        GLFW_KEY_5,             // 31 NUM_5
        GLFW_KEY_6,             // 32 NUM_6
        GLFW_KEY_7,             // 33 NUM_7
        GLFW_KEY_8,             // 34 NUM_8
        GLFW_KEY_9,             // 35 NUM_9
        GLFW_KEY_ESCAPE,        // 36 ESCAPE
        GLFW_KEY_SPACE,         // 37 SPACE
        GLFW_KEY_APOSTROPHE,    // 38 APOSTROPHE
        GLFW_KEY_COMMA,         // 39 COMMA
        GLFW_KEY_MINUS,         // 40 MINUS
        GLFW_KEY_PERIOD,        // 41 PERIOD
        GLFW_KEY_SLASH,         // 42 SLASH
        GLFW_KEY_SEMICOLON,     // 43 SEMICOLON
        GLFW_KEY_EQUAL,         // 44 EQUAL - GLFW_KEY_KP_EQUAL is NOT mapped
        GLFW_KEY_LEFT_BRACKET,  // 45 LEFT_BRACKET
        GLFW_KEY_BACKSLASH,     // 46 BACKSLASH
        GLFW_KEY_RIGHT_BRACKET, // 47 RIGHT_BRACKET
        GLFW_KEY_GRAVE_ACCENT,  // 48 GRAVE_ACCENT
        GLFW_KEY_ENTER,         // 49 ENTER - GLFW_KEY_KP_ENTER is NOT mapped
        GLFW_KEY_TAB,           // 50 TAB
        GLFW_KEY_BACKSPACE,     // 51 BACKSPACE
        GLFW_KEY_INSERT,        // 52 INSERT
        GLFW_KEY_DELETE,        // 53 DELETE
        GLFW_KEY_RIGHT,         // 54 RIGHT
        GLFW_KEY_LEFT,          // 55 LEFT
        GLFW_KEY_DOWN,          // 56 DOWN
        GLFW_KEY_UP,            // 57 UP
        GLFW_KEY_PAGE_UP,       // 58 PAGE_UP
        GLFW_KEY_PAGE_DOWN,     // 59 PAGE_DOWN
        GLFW_KEY_HOME,          // 60 HOME
        GLFW_KEY_END,           // 61 END
        GLFW_KEY_CAPS_LOCK,     // 62 CAPS_LOCK
        GLFW_KEY_SCROLL_LOCK,   // 63 SCROLL_LOCK
        GLFW_KEY_NUM_LOCK,      // 64 NUM_LOCK
        GLFW_KEY_PRINT_SCREEN,  // 65 PRINT_SCREEN
        GLFW_KEY_PAUSE,         // 66 PAUSE
        GLFW_KEY_F1,            // 67 F1
        GLFW_KEY_F2,            // 68 F2
        GLFW_KEY_F3,            // 69 F3
        GLFW_KEY_F4,            // 70 F4
        GLFW_KEY_F5,            // 71 F5
        GLFW_KEY_F6,            // 72 F6
        GLFW_KEY_F7,            // 73 F7
        GLFW_KEY_F8,            // 74 F8
        GLFW_KEY_F9,            // 75 F9
        GLFW_KEY_F10,           // 76 F10
        GLFW_KEY_F11,           // 77 F11
        GLFW_KEY_F12,           // 78 F12
        GLFW_KEY_F13,           // 79 F13
        GLFW_KEY_F14,           // 80 F14
        GLFW_KEY_F15,           // 81 F15
        GLFW_KEY_F16,           // 82 F16
        GLFW_KEY_F17,           // 83 F17
        GLFW_KEY_F18,           // 84 F18
        GLFW_KEY_F19,           // 85 F19
        GLFW_KEY_F20,           // 86 F20
        GLFW_KEY_F21,           // 87 F21
        GLFW_KEY_F22,           // 88 F22
        GLFW_KEY_F23,           // 89 F23
        GLFW_KEY_F24,           // 90 F24
        GLFW_KEY_F25,           // 91 F25
        GLFW_KEY_KP_0,          // 92 NUMPAD_0
        GLFW_KEY_KP_1,          // 93 NUMPAD_1
        GLFW_KEY_KP_2,          // 94 NUMPAD_2
        GLFW_KEY_KP_3,          // 95 NUMPAD_3
        GLFW_KEY_KP_4,          // 96 NUMPAD_4
        GLFW_KEY_KP_5,          // 97 NUMPAD_5
        GLFW_KEY_KP_6,          // 98 NUMPAD_6
        GLFW_KEY_KP_7,          // 99 NUMPAD_7
        GLFW_KEY_KP_8,          // 100 NUMPAD_8
        GLFW_KEY_KP_9,          // 101 NUMPAD_9
        GLFW_KEY_KP_DECIMAL,    // 102 DECIMAL
        GLFW_KEY_KP_DIVIDE,     // 103 DIVIDE
        GLFW_KEY_KP_MULTIPLY,   // 104 MULTIPLY
        GLFW_KEY_KP_SUBTRACT,   // 105 SUBSTRACT
        GLFW_KEY_KP_ADD,        // 106 ADD
        GLFW_KEY_LEFT_SHIFT,    // 107 LEFT_SHIFT
        GLFW_KEY_LEFT_CONTROL,  // 108 LEFT_CONTROL
        GLFW_KEY_LEFT_ALT,      // 109 LEFT_ALT
        GLFW_KEY_LEFT_SUPER,    // 110 LEFT_SYSTEM
        GLFW_KEY_RIGHT_SHIFT,   // 111 RIGHT_SHIFT
        GLFW_KEY_RIGHT_CONTROL, // 112 RIGHT_CONTROL
        GLFW_KEY_RIGHT_ALT,     // 113 RIGHT_ALT
        GLFW_KEY_RIGHT_SUPER,   // 114 RIGHT_SYSTEM
        GLFW_KEY_MENU           // 115 MENU
      };
    }
  }
}
