#include <string.h>
#include "config/video.h"

// Parameters:
//   w: width of the image
//   h: height of the image
//   durationMovie: duration in seconds of movie (colored image)
//   durationCredits: duration in seconds of credits (black-and-white image)
//   fps: Frames Per Second
//   unit: Unit of the output value. It could be 'bt' (bytes), 'ko' (kilobytes), 'mo' (megabytes), 'go' (gigabytes)
// Return value:
//   Video size in the specified unit
float video(int w, int h, int durationMovie, int durationCredits, int fps, char* unit) {
    // Constants for unit conversion
    const float BYTE_TO_KB = 1024.0;
    const float BYTE_TO_MB = 1024.0 * 1024.0;
    const float BYTE_TO_GB = 1024.0 * 1024.0 * 1024.0;

    // Calculate size of the colored section
    long long colorSectionSize = (long long)w * h * 3 * fps * durationMovie;

    // Calculate size of the black-and-white section
    long long bwSectionSize = (long long)w * h * 1 * fps * durationCredits;

    // Total size in bytes
    long long totalSize = colorSectionSize + bwSectionSize;

    // Convert size based on the specified unit
    if (strcmp(unit, "bt") == 0) {
        return (float)totalSize; // Bytes
    } else if (strcmp(unit, "ko") == 0) {
        return (float)totalSize / BYTE_TO_KB; // Kilobytes
    } else if (strcmp(unit, "mo") == 0) {
        return (float)totalSize / BYTE_TO_MB; // Megabytes
    } else if (strcmp(unit, "go") == 0) {
        return (float)totalSize / BYTE_TO_GB; // Gigabytes
    } else {
        // Invalid unit, return 0
        return 0;
    }
}
