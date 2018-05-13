cmake_minimum_required(VERSION 2.8)	 # Проверка версии CMake.
										# Если версия установленой программы
										# старее указаной, произайдёт аварийный выход.

project(hello_world)			# Название проекта

set(SOURCE_EXE main.cpp)		# Установка переменной со списком исходников для исполняемого файла

add_executable(main ${SOURCE_EXE})	# Создает исполняемый файл с именем main

set_property(TARGET main PROPERTY CXX_STANDARD 14)

find_package (Threads) 
target_link_libraries (main ${CMAKE_THREAD_LIBS_INIT})

