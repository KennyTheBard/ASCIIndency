### TODO List

# Developing
- [ ] Filter appliance method
- [ ] Free/Constant-ratio resizing method
- [ ] Pixel to ASCII 1:1 transformation
- [x] Grayscale

# Implementing
- [x] Implement Netpbm decoding for .pnm and .pgm
- [ ] Extend Netpbm decoding to all Netpbm formats
- [ ] Implement Netpbm encoding for .pnm and .pgm
- [ ] Extend Netpbm encoding to all Netpbm formats

# Refactoring
- [x] Move decoding functions to a different file
- [x] Move ecoding functions to a different file
- [ ] Move decoding & encoding helper functions to a different file
- [ ] Find safer alternative to raw pointers in image setters/getters

# Testing
- [ ] Write unit test for Netpbm decoding
- [ ] Write more unit tests for image class
- [ ] Test grayscale function
- [ ] Test casting functions (from transformation.h)

# Debugging
- [ ] Problem with set_pixels in image (see image_ut)
