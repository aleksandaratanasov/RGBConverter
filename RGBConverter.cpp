/*
 * RGBConverter.h - Arduino library for converting between RGB, HSV and HSL
 *
 * Ported from the Javascript at http://mjijackson.com/2008/02/rgb-to-hsl-and-rgb-to-hsv-color-model-conversion-algorithms-in-javascript
 * The hard work was Michael's, all the bugs are mine.
 *
 * Robert Atkins, December 2010 (ratkins_at_fastmail_dot_fm).
 *
 * https://github.com/ratkins/RGBConverter
 *
 * Modifications by Aleksandar Vladimirov Atanasov, September 2015
 *  - all functions are now not bound to Arduino's header
 *  - added conversion for single and full RGB color values from/to float to/from integer
 *  - all doubles have been converted to floats (no need for great accuracy here)
 *  - array arguments have been split into triplets of pointers (one pointer per value)
 *  - all functions are now static so there is no need for creating the RGBConverter object (constructor of RGBConverter has also been moved to private)
 *  - added alternative display of HSL using degrees and percentages
 *  - reformatted documentation
 */
#include "RGBConverter.h"
#include <cmath>

// Unit conversions
void RGBConverter::rgbIntToFloat_single(int x, float *_x) {
    *_x = x/255.;
}

void RGBConverter::rgbIntToFloat(int r, int g, int b, float *_r, float *_g, float *_b) {
    rgbIntToFloat_single(r, _r);
    rgbIntToFloat_single(g, _g);
    rgbIntToFloat_single(b, _b);
}

void RGBConverter::rgbFloatToInt_single(float x, int *_x) {
    *_x = floor(x == 1.0 ? 255 : x * 256.0);
}

void RGBConverter::rgbFloatToInt(float r, float g, float b, int *_r, int *_g, int *_b) {
    rgbFloatToInt_single(r, _r);
    rgbFloatToInt_single(g, _g);
    rgbFloatToInt_single(b, _b);
}

void RGBConverter::hslIntervalZeroOneToDegAndPercentage(float h, float s, float l, float *_h, float *_s, float *_l) {
    *_h = h*360.;
    *_s = s*100.;
    *_l = l*100.;
}

void RGBConverter::hslDegAndPercentageToIntervalZeroOne(float h, float s, float l, float *_h, float *_s, float *_l) {
    *_h = h/360.;
    *_s = s/100.;
    *_l = l/100.;
}

// Color value conversions
void RGBConverter::rgbToHsl(float r, float g, float b, float *h, float *s, float *l) {
    float max = threeway_max(r, g, b);
    float min = threeway_min(r, g, b);
    *l = (max + min) / 2;

    if (max == min) {
        *h = *s = 0.; // achromatic
    } else {
        float d = max - min;
        *s = *l > .5 ? d / (2. - max - min) : d / (max + min);
        if (max == r){
            *h = (g - b) / d + (g < b ? 6. : 0.);
        } else if (max == g) {
            *h = (b - r) / d + 2.;
        } else if (max == b) {
            *h = (r - g) / d + 4.;
        }
        *h /= 6;
    }
}

void RGBConverter::hslToRgb(float h, float s, float l, float *r, float *g, float *b) {
    if (s == 0.) {
        *r = *g = *b = l; // achromatic
    } else {
        float q = l < .5 ? l * (1 + s) : l + s - l * s;
        float p = 2. * l - q;
        *r = RGBConverter::hueToRgb(p, q, h + 1/3.);
        *g = RGBConverter::hueToRgb(p, q, h);
        *b = RGBConverter::hueToRgb(p, q, h - 1/3.);
    }
}

void RGBConverter::rgbToHsv(float r, float g, float b, float *h, float *s, float *v) {
    float max = threeway_max(r, g, b), min = threeway_min(r, g, b);
    *v = max;

    float d = max - min;
    *s = max == 0. ? 0. : d / max;

    if (max == min) { 
        *h = 0.; // achromatic
    } else {
        if (max == r) {
            *h = (g - b) / d + (g < b ? 6. : 0.);
        } else if (max == g) {
            *h = (b - r) / d + 2.;
        } else if (max == b) {
            *h = (r - g) / d + 4.;
        }
        *h /= 6.;
    }
}

void RGBConverter::hsvToRgb(float h, float s, float v, float *r, float *g, float *b) {

    int i = int(h * 6);
    float f = h * 6 - i;
    float p = v * (1 - s);
    float q = v * (1 - f * s);
    float t = v * (1 - (1 - f) * s);

    switch(i % 6){
        case 0: *r = v, *g = t, *b = p; break;
        case 1: *r = q, *g = v, *b = p; break;
        case 2: *r = p, *g = v, *b = t; break;
        case 3: *r = p, *g = q, *b = v; break;
        case 4: *r = t, *g = p, *b = v; break;
        case 5: *r = v, *g = p, *b = q; break;
    }
}
 
float RGBConverter::threeway_max(float a, float b, float c) {
    return fmax(a, fmax(b, c));
}

float RGBConverter::threeway_min(float a, float b, float c) {
    return fmin(a, fmin(b, c));
}

float RGBConverter::hueToRgb(float p, float q, float t) {
    if(t < 0.) t += 1;
    if(t > 1.) t -= 1;
    if(t < 1/6.) return p + (q - p) * 6. * t;
    if(t < 1/2.) return q;
    if(t < 2/3.) return p + (q - p) * (2/3. - t) * 6.;
    return p;
}
