#include <iostream>
#include <opencv2/opencv.hpp>
#include <chrono>
#include <omp.h>

using namespace cv;
using namespace std;
using namespace std::chrono;

int main(int argc, char *argv[]){

	if (argc != 4) {
        cerr << "Uso: " << argv[0] << " <imagen_color> <imagen_gris> <num_hebras>" << endl;
        return -1;
    }

	    // Leer parámetros de entrada
    	string inputImage = argv[1];
    	string outputImage = argv[2];
    	int numThreads = stoi(argv[3]);

	// Se lee la imagen a color
	Mat image = imread(inputImage, IMREAD_COLOR);

	if (image.empty()) {
		cerr << "Error al cargar la imagen." << endl;
		return -1;
	}


    // Mostrar información sobre la imagen
        cout << "Loading image..." << endl;
        cout << "Rows (height): " << image.rows << " Cols (width): " << image.cols << endl;


	// Metodo de luminosidad en paralelo
	Mat grayImage(image.rows, image.cols, CV_8UC1);


	 // Inicia el cronómetro
    auto start = high_resolution_clock::now();

 	 // Utilizando OpenMP
	#pragma omp parallel for num_threads(numThreads)
	for (int r = 0; r < image.rows; r++) {
		for (int c = 0; c < image.cols; c++) {
			Vec3b pixel = image.at<Vec3b> (r, c);
			grayImage.at<uchar>(r, c) = static_cast<uchar>((pixel[0] + pixel[1] + pixel[2]) / 3);
		}
	}

	// Detiene el cronómetro
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);

       // Imprimw el tiempo de ejecución en segundos
     cout << "\nTiempo de ejecución: " << duration.count() / 1e6 << " segundos" << endl;

      // Guarda la imagen en escala de grises
    imwrite(outputImage, grayImage);


	return 0;
}
