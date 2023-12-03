#include <iostream>
#include <opencv2/opencv.hpp>
#include <chrono>

using namespace cv;
using namespace std;
using namespace std::chrono;


int main(int argc, char *argv[]){

 if (argc != 3) {
        cerr << "Uso: " << argv[0] << " <imagen_color> <imagen_gris>" << endl;
        return -1;
    }


         // Lee parámetros de entrada
       string inputImage = argv[1];
        string outputImage = argv[2];

	// Lee la imagen en color
	Mat image =imread("imageacolor.jpg", IMREAD_COLOR);

	if(image.empty()) {
		cerr << "Error al cargar la imagen." << endl;
		return -1;
	}

        // Mostrar información sobre la imagen
    cout << "Loading image..." << endl;
    cout << "Rows (height): " << image.rows << " Cols (width): " << image.cols << endl;

	 // Inicia el cronómetro
    auto start = high_resolution_clock::now();

	// Convertir a escala de grises (metodo de luminosidad)
	Mat grayImage;
	cvtColor(image, grayImage, COLOR_BGR2GRAY);

	// Imprime los pixeles de la imagen en escala de grises
	for (int r = 0; r < grayImage.rows; r++) {
		for (int c = 0; c < grayImage.cols; c++) {
			cout << static_cast<int>(grayImage.at<uchar>(r, c)) << " ";
		}
		cout << endl;
	}
	  // Detiene el cronómetro
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);

   	 // Imprime el tiempo de ejecución en segundos
   	 cout << "Total time spent in seconds is " << duration.count() / 1e6 << endl;

        // Guarda la imagen en escala de grises
        imwrite(outputImage, grayImage);

	  // Imprime los detalles de salida
       cout << "Resultado guardado en: " << outputImage << endl;
       cout << "Tiempo de ejecución: " << duration.count() / 1e6 << " segundos" << endl;



	return 0;
}
