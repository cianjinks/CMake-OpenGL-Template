cmake_minimum_required(VERSION 3.3)
project(STB_IMAGE)

add_library(stb_image include/stb_image.h stb_image_impl.c)
target_include_directories(stb_image PUBLIC include/)