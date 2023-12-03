#include <iostream>
#include <opencv2/opencv.hpp>
#include <omp.h>

using namespace cv;
using namespace std;

int main(){
	// Se lee la imagen a color
	Mat image = imread("imagenacolor.jpg", IMREAD_COLOR);

	if (image.empty()) {
		cerr << "Error al cargar la imagen." << endl;
		return -1;
	}

	// Convertir a escala de grises (metodo de luminosidad en paralelo)
	Mat gray(image.rows, image.cols, CV_8UC1);

	#pragma omp parallel for
	for (int f = 0; r < image.filas; f++) {
		for (int c = 0; c < image.columnas; c++) {
			Vec3b pixel = image.at<Vec3b> (f, c);
			grayImage.at<uchar>(r, c) = static_cast<uchar>((pixel[0] + pixel[1] pixel[2]) / 3);
		}
	}

	// Imprimir algunos pixeles de la imagen en escala de grises
	for (int f = 0; f < grayImage.filas; f++) {
		for (int c = 0; c < grayImage.columnas; c++) {
			cout << static_cast<int>(grayImage.at<uchar>(f, c)) << " ";
		}
		cout << endl;
	}
	return 0;
}
