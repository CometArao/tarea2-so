#include <iostream>
#include <opencv2/opencv.hpp>
#include <chrono>
#include <thread>
#include <vector>

using namespace cv;
using namespace std;
using namespace std::chrono;

void convertToGrayscale(const Mat& input, Mat& output, int startRow, int endRow) {
    for (int r = startRow; r < endRow; r++) {
        for (int c = 0; c < input.cols; c++) {
            Vec3b pixel = input.at<Vec3b>(r, c);
            uchar grayValue = (pixel[0] + pixel[1] + pixel[2]) / 3;
            output.at<uchar>(r, c) = grayValue;
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        cerr << "Uso: " << argv[0] << " <imagen_color> <imagen_gris> <num_hebras>" << endl;
        return -1;
    }

    // Lee parámetros de entrada
    string inputImage = argv[1];
    string outputImage = argv[2];
    int numThreads = stoi(argv[3]);

    // Lee la imagen en color
    Mat image = imread(inputImage, IMREAD_COLOR);

    if (image.empty()) {
        cerr << "Error al cargar la imagen." << endl;
        return -1;
    }
    // Muestra información sobre la imagen
    cout << "Cargando imagen..." << endl;
    cout << "Rows (height): " << image.rows << " Cols (width): " << image.cols << endl;

    // Crea una matriz en escala de grises del mismo tamaño que la imagen a color
    Mat grayImage(image.rows, image.cols, CV_8UC1);


    // Inicia el cronómetro
    auto start = high_resolution_clock::now();

    // Utilizando threads con el número de hebras especificado
    vector<thread> threads;
    int rowsPerThread = image.rows / numThreads;

    cout << "Empieza la conversión..." << endl;
    for (int i = 0; i < numThreads; ++i) {
        int startRow = i * rowsPerThread;
        int endRow = (i == numThreads - 1) ? image.rows : (i + 1) * rowsPerThread;
        threads.emplace_back(convertToGrayscale, cref(image), ref(grayImage), startRow, endRow);
    }

    // Espera a que todos los threads terminen
    for (auto &thread : threads) {
        thread.join();
    }

    // Detiene el cronómetro
    auto stop = high_resolution_clock::now();
    cout << "Se detiene la conversión..." << endl;

    imwrite(outputImage, grayImage);

    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Tiempo de ejecución: " << duration.count() / 1e6 << " segundos" << endl;

    return 0;
}
