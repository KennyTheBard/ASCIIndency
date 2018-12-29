test_image: image_ut.cpp
	g++ image_ut.cpp image.cpp -o test_image

clear_tests:
	rm test_*
