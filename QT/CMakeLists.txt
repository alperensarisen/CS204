cmake_minimum_required(VERSION 3.16)

project(MyQtApp VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Qt6 klasör yolu
set(CMAKE_PREFIX_PATH "C:/Qt/6.10.1/mingw_64/lib/cmake/Qt6")

# Qt6 modüllerini bul
find_package(Qt6 COMPONENTS Core Widgets REQUIRED)

# Qt MOC / UIC / RCC sistemlerini aç
qt_standard_project_setup()

# Tek dosya derlenecek
add_executable(MyQtApp
    main.cpp
)

# Qt6 ile linkle
target_link_libraries(MyQtApp PRIVATE Qt6::Core Qt6::Widgets)
