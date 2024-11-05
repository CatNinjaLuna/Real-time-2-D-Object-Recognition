# Image Processing and Classification Project

## Name: Carolina Li

## I sumbitted 7 days late without doing the extension of the project.

## OS and IDE

-  MacOS 15.0.1
-  IDE Visual Studio Code 1.95.0

2. **Clone the Repository:**
   ```sh
   git clone <repository-url>
   cd <repository-directory>
   ```

## Link

https://drive.google.com/file/d/1_ghBbc6emImuOgBNjnLJ-LLIy1zm-lpA/view?usp=sharing

# Compilation and Execution

Navigate to the Project Directory:
cd /path/to/your/project/directory

# Compile the Code:

````sh

task 1:
g++ -std=c++17 -o task1 task1.cpp `pkg-config --cflags --libs opencv4`
./task1 P3_dataset task1_Demo 128

task2:
g++ -std=c++17 -o task2 task2.cpp `pkg-config --cflags --libs opencv4`
./task1 P3_dataset task2_result 128

task3:
g++ -std=c++17 -o task3 task3.cpp `pkg-config --cflags --libs opencv4`
./task1 P3_dataset task3_result 128

task4:
g++ -std=c++17 -o task4 task4.cpp `pkg-config --cflags --libs opencv4`
./task1 P3_dataset task4_result 128

task5:
g++ -std=c++17 -o task5 task5.cpp `pkg-config --cflags --libs opencv4`
./task1 P3_dataset task5_result 128

task6:
g++ -std=c++17 -o task6 task6.cpp `pkg-config --cflags --libs opencv4`
./task6 P3_dataset task6_Demo 100 5 features.csv

task7:
g++ -std=c++17 -o task7 task7.cpp `pkg-config --cflags --libs opencv4`
./task1 P3_dataset task7_result 128

task9:
g++ -std=c++17 -o task9 task9.cpp `pkg-config --cflags --libs opencv4`
./task1 P3_dataset task9_result 128

#  Run the Compiled Binary
```sh
./task6 <input_directory> <output_directory> <min_region_size> <max_regions> <feature_file>
<input_directory>: The directory containing the input images.
<output_directory>: The directory where the output images will be saved.
<min_region_size>: The minimum size of regions to be considered.
<max_regions>: The maximum number of regions to process.
<feature_file>: The path to the feature file containing known objects.

````
