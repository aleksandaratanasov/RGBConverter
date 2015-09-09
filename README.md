# Original README from initial fork

NOTE: This code has been fairly much obviated by the HSV-RGB functions in the new FastSPI 2 library (http://code.google.com/p/fastspi/)

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
 */

# Added to README after initial fork

**CHANGELOG**

v0.1

 * All functions are now not bound to Arduino's header
 * Added conversion for single and full RGB color values from/to float to/from integer
 * All doubles have been converted to floats (no need for great accuracy here)
 * Array arguments have been split into triplets of pointers (one pointer per value)
 * Aall functions are now static so there is no need for creating the RGBConverter object (constructor of RGBConverter has also been moved to private)
 * Added alternative display of HSL using degrees and percentages
 * Reformatted documentation
 * Added example executable
