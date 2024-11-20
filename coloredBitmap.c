#include <string.h>
#include "config/coloredBitmap.h"
// Parameters:
//   w: width of the image
//   h: height of the image
//   u: Unit of the output value. It could be 'bt' bits, 'ko' kilobits, 'mo' megabits, 'go' gigabits
// Return value:
//   colored image size Bitmap (based on the unit passed parameter)
float coloredBitmap(int w, int h, char* unit) {
    // Calculate the size in bits
    float sizeInBits = (float)(w * h * 24);

    // Check the unit and convert accordingly
    if (strcmp(unit, "bt") == 0) {
        return sizeInBits; // Bits
    } else if (strcmp(unit, "ko") == 0) {
        return sizeInBits / 8192.0; // 1 kilobit = 1024 bits, so divide by 8*1024
    } else if (strcmp(unit, "mo") == 0) {
        return sizeInBits / (8192.0 * 1024); // 1 megabit = 1024 kilobits
    } else if (strcmp(unit, "go") == 0) {
        return sizeInBits / (8192.0 * 1024 * 1024); // 1 gigabit = 1024 megabits
    } else {
        // Return 0 for an invalid unit
        return 0;
    }
}
