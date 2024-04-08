// keyboard_scancodes.h

#ifndef KEYBOARD_SCANCODES_H
#define KEYBOARD_SCANCODES_H

// Define the keyboard map array
char keyboard_map[128] = {
    0, 0, '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', '-', '=',
    '\b', // Backspace
    '\t', // Tab
    'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p', '[', ']', '\n', // Enter
    0, // Left Control
    'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l', ';', '\'', '`', 
    0, // Left Shift
    '\\', 'z', 'x', 'c', 'v', 'b', 'n', 'm', ',', '.', '/', 
    0, // Right Shift
    '*', // Keypad *
    0, // Left Alt
    ' ', // Spacebar
    0, // Caps Lock
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, // F1 - F10
    0, // Num Lock
    0, // Scroll Lock
    '7', // Keypad 7
    '8', // Keypad 8
    '9', // Keypad 9
    '-', // Keypad -
    '4', // Keypad 4
    '5', // Keypad 5
    '6', // Keypad 6
    '+', // Keypad +
    '1', // Keypad 1
    '2', // Keypad 2
    '3', // Keypad 3
    '0', // Keypad 0
    '.', // Keypad .
    0, 0, 0, // Unused keys
    0, // F11
    0  // F12
};

#endif // KEYBOARD_SCANCODES_H
