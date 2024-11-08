/*
Author: Carolina Li
Date: Oct/28/2024
File: task2.cpp
Purpose: This code applies a binary threshold and noise reduction to images from an input directory,
displays the results, and saves them to an output directory.
*/

#include <opencv2/opencv.hpp>
#include <iostream>
#include <filesystem>
#include <string>

namespace fs = std::filesystem;

// Converts the image to grayscale and applies a manual binary threshold.
cv::Mat manual_threshold(const cv::Mat& frame, int threshold_value) {
    cv::Mat gray, thresholded;
    cv::cvtColor(frame, gray, cv::COLOR_BGR2GRAY);
    thresholded = cv::Mat::zeros(gray.size(), gray.type());

    for (int i = 0; i < gray.rows; ++i) {
        for (int j = 0; j < gray.cols; ++j) {
            if (gray.at<uchar>(i, j) > threshold_value) {
                thresholded.at<uchar>(i, j) = 255;
            } else {
                thresholded.at<uchar>(i, j) = 0;
            }
        }
    }
    return thresholded;
}

// Cleans noise in the thresholded image using morphological operations.
cv::Mat clean_image(const cv::Mat& thresholded) {
    cv::Mat cleaned;
    cv::Mat kernel = cv::getStructuringElement(cv::MORPH_RECT, cv::Size(3, 3));
    cv::morphologyEx(thresholded, cleaned, cv::MORPH_CLOSE, kernel);
    cv::morphologyEx(cleaned, cleaned, cv::MORPH_OPEN, kernel);
    return cleaned;
}

 // Iterates through images, applies thresholding and cleaning, displays, and saves them.
void process_images(const std::string& input_directory, const std::string& output_directory, int threshold_value) {
    // Ensure the output directory exists
    if (!fs::exists(output_directory)) {
        fs::create_directory(output_directory);
    }

    for (int i = 1; ; ++i) {
        std::string image_name = "img" + std::to_string(i) + "p3.png";
        std::string input_path = input_directory + "/" + image_name;
        std::string output_path = output_directory + "/" + image_name;

        std::cout << "Processing: " << input_path << std::endl;

        if (!fs::exists(input_path)) {
            std::cout << "Image not found: " << input_path << std::endl;
            break; // Stop if the image does not exist
        }

        cv::Mat frame = cv::imread(input_path);
        if (frame.empty()) {
            std::cerr << "Error: Could not read image file " << input_path << std::endl;
            continue;
        }

        cv::Mat thresholded = manual_threshold(frame, threshold_value);
        cv::Mat cleaned = clean_image(thresholded);
        cv::imshow("Thresholded Image", thresholded);
        cv::imshow("Cleaned Image", cleaned);
        cv::waitKey(0); // Wait for a key press to move to the next image

        // Save the cleaned image
        std::cout << "Saving: " << output_path << std::endl;
        if (!cv::imwrite(output_path, cleaned)) {
            std::cerr << "Error: Could not save image to " << output_path << std::endl;
        }
    }

    cv::destroyAllWindows();
}

// Validates input arguments and initiates image processing if input path is a directory.
int main(int argc, char** argv) {
    if (argc < 4) {
        std::cerr << "Usage: " << argv[0] << " <input_directory> <output_directory> <threshold_value>" << std::endl;
        return -1;
    }

    std::string input_directory = argv[1];
    std::string output_directory = argv[2];
    int threshold_value = std::stoi(argv[3]);

    if (fs::is_directory(input_directory)) {
        process_images(input_directory, output_directory, threshold_value);
    } else {
        std::cerr << "Error: Provided input path is not a directory." << std::endl;
        return -1;
    }

    return 0;
}