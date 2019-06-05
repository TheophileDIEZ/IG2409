#include <iostream>
#include <filesystem>
#include <algorithm>
#include <opencv2/stitching.hpp>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;
using namespace filesystem;

void getFiles(path);
int parseArgs(int argc, char **argv);

path p;
vector<Mat> imgs;

int stitcher(int argc, char **argv) {
	int exit_val = parseArgs(argc, argv);
	if (exit_val) return EXIT_FAILURE;

	
	Mat pano;
	Ptr<Stitcher> stitcher = Stitcher::create(Stitcher::PANORAMA);
	Stitcher::Status status = stitcher->stitch(imgs, pano);

	if (status != Stitcher::OK)
	{
		cout << "Can't stitch images, error code = " << int(status) << endl;
		return EXIT_FAILURE;
	}
	//![stitching]

	imwrite("output.jpg", pano);
	cout << "stitching completed successfully\n output.jpg saved!";
	return EXIT_SUCCESS;
}

void getFiles(path p)
{
	directory_iterator it = directory_iterator::directory_iterator(p);
	list<string> supportedTypes {".bmp", ".pbm", ".pgm", ".ppm", ".sr", ".ras", ".jpeg", ".jpg", ".jpe", ".jp2", ".tiff", ".tif", ".png" };
	for (auto& ptr : it) {
		if (std::find(supportedTypes.begin(), supportedTypes.end(), ptr.path().extension()) != supportedTypes.end()) {
			cout << "\t[  SUPPORTED  ] " << ptr.path().filename() << endl;
		}
		else {
			cout << "\t[NOT SUPPORTED] " << ptr.path().filename() << endl;
		}
	}
	for (auto& ptr : directory_iterator::directory_iterator(p)) {
		if (std::find(supportedTypes.begin(), supportedTypes.end(), ptr.path().extension()) != supportedTypes.end()) {
			Mat img = imread(ptr.path().string());
			if (img.empty())
			{
				cout << "Can't read image '" << ptr.path() << "'\n";
			}
			else
				imgs.push_back(img);
		}
	}
}

int parseArgs(int argc, char ** argv)
{
	if (argc < 3)
	{
		cout << "fail on arg count : expected >= 3 , got " << argc << endl;
		cout << "Usage : " << argv[0] << " [-d Directory | -f file1 file2 [files]]" << endl;
		return EXIT_FAILURE;
	}
	if ((argv[1] == "-d" || argv[1] == "-f") && !(argv[1] == "-d" && argv[1] == "-f"))
	{
		cout << "fail on argument : expected -d or -f , got " << argv[1] << endl;
		cout << "Usage : " << argv[0] << " [-d Directory | -f file1 file2 [files]]" << endl;
		return EXIT_FAILURE;
	}

	switch (argv[1][1])
	{
	case 'd':
		cout << "MODE directory" << endl;
		p = path::path(argv[2]);
		if (is_directory(p))
		{
			cout << "[PASS] PATH : " << argv[2] << endl;
			getFiles(p);
		}
		else
		{
			cout << "[FAIL] PATH : " << argv[2] << endl;
			cerr << "\t Not a directory path" << endl;
			return EXIT_FAILURE;
		}
		break;
	case 'f':
		cout << "MODE file" << endl;
		cout << "PATHS : " << endl;
		for (size_t i = 2; i < argc; i++)
		{
			cout << "\t" << argv[2] << endl;
		}
		break;
	default:
		cout << "Usage : " << argv[0] << " [-d Directory | -f file1 file2 [files]]" << endl;
		break;
	}
	return EXIT_SUCCESS;
}
