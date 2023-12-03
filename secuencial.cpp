#include <iostream>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;


int main() {
	// Ler la imagen en color
	Mat image =imread("imageacolor.jpg", IMREAD_COLOR);

	if(image.empty()) {
		cerr << "Error al cargar la imagen." << endl;
		return -1;
	}

	// Convertir a escala de grises (metodo de luminosidad)
	Mat grayImage;
	cvtColor(Image, grayImage, COLOR_BGR2GRAY);

	// Imprimir a algunos pixeles de la imagen en escala de grises
	for (int f = 0; f < grayImage.filas; f++) {
		for (int c = 0; c < grayImage.columnas; c++) {
			cout << static_cast<int>(grayImage.at<uchar>(f, c) << " ";
		}
		cout << endl;
	}

	return 0;
}
