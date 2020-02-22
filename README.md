# Tesseract_OCR

- Version 1.0

# About

- This project complete the picture OCR automatic recognition.

- Tesseract OCR lang file (tessata/eng.traineddata) was trained using this Gist script file and a License Plate font.

# Requirements:

**Tesseract 4.0(x64) and leptonica-1.76.0 libraries.**

**Visual Studio 2015**

# Installation

- You should have the following folder structure:

**Load the path of the bin file in the TesseractOCR into the system environment variable.**

# Usage

- Here is the default workflow to extract text from an image:

- Instantiate Tesseract with data path and language

- Set variables (character set, …)

- Set the image to analyze

- Start recognition

- Get recognized text

- Clear


# Improvements

- Improve image processing.

- Improve square (plate) detection.

- Perspective transform (or 3D).

- Improve contour detection algorithm.

- Improve ROI license plate area.

- Better image crop.


