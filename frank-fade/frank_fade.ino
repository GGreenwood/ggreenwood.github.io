#include <avr/pgmspace.h>

#define LED_PIN 11
#define DELAY   15

// Max and Min brightness must be between 0 and 255
#define MIN_BRIGHTNESS  0
#define MAX_BRIGHTNESS  255

#define NUM_SAMPLES 256

static const unsigned char table[NUM_SAMPLES] PROGMEM = 
{
    0,  0,  0,  0,  0,  0,  0,  0,
    0,  0,  0,  0,  0,  0,  1,  1,
    1,  1,  1,  2,  2,  2,  2,  3,
    3,  3,  4,  4,  5,  5,  5,  6,
    6,  7,  7,  8,  8,  9,  9,  10,
    11, 11, 12, 12, 13, 14, 15, 15,
    16, 17, 17, 18, 19, 20, 21, 22,
    22, 23, 24, 25, 26, 27, 28, 29,
    30, 31, 32, 33, 34, 35, 36, 37,
    38, 40, 41, 42, 43, 44, 45, 47,
    48, 49, 50, 52, 53, 54, 55, 57,
    58, 59, 61, 62, 64, 65, 66, 68,
    69, 71, 72, 73, 75, 76, 78, 79,
    81, 82, 84, 85, 87, 88, 90, 91,
    93, 94, 96, 98, 99, 101,    102,    104,
    106,    107,    109,    110,    112,    114,    115,    117,
    118,    120,    122,    123,    125,    126,    128,    130,
    131,    133,    135,    136,    138,    139,    141,    143,
    144,    146,    148,    149,    151,    152,    154,    156,
    157,    159,    160,    162,    163,    165,    167,    168,
    170,    171,    173,    174,    176,    177,    179,    180,
    182,    183,    185,    186,    188,    189,    191,    192,
    193,    195,    196,    198,    199,    200,    202,    203,
    204,    206,    207,    208,    209,    211,    212,    213,
    214,    215,    217,    218,    219,    220,    221,    222,
    223,    224,    226,    227,    228,    229,    230,    231,
    232,    232,    233,    234,    235,    236,    237,    238,
    239,    239,    240,    241,    242,    242,    243,    244,
    244,    245,    246,    246,    247,    247,    248,    248,
    249,    249,    250,    250,    251,    251,    251,    252,
    252,    252,    253,    253,    253,    253,    254,    254,
    254,    254,    254,    254,    254,    254,    254,    255
};

uint8_t lookup(uint8_t value) {
    return pgm_read_byte(&(table[value % NUM_SAMPLES]));
}

void setup() {
}

// 1 is increasing, 0 is decreasing
uint8_t direction = 1;

uint8_t brightness = 0;

void loop() {
    analogWrite(LED_PIN, lookup(brightness));
    if(direction == 1) {
        brightness++;
        if(brightness >= MAX_BRIGHTNESS) {
            direction = 0;
        }
    } else {
        brightness--;
        if(brightness <= MIN_BRIGHTNESS) {
            direction = 1;
        }
    }
    delay(DELAY);
}
