cmake_minimum_required(VERSION 3.28)
project(Pract_Proj)

set(CMAKE_CXX_STANDARD 17)

add_executable(Pract_Proj main.cpp
        headers.h
        Jewel/Jewel.cpp
        Jewel/Jewel.h
        Pearl/Pearl.cpp
        Pearl/Pearl.h
        Emerald/Emerald.cpp
        Emerald/Emerald.h
        Diamond/Diamond.cpp
        Diamond/Diamond.h
        Necklace/Necklace.cpp
        Necklace/Necklace.h
        JewelFactory/JewelFactory.cpp
        JewelFactory/JewelFactory.h
        JewelryShop/JewelryShop.cpp
        JewelryShop/JewelryShop.h)
