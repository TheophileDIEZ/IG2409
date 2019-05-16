#include <iostream>
#include <filesystem>
#include <algorithm>

using namespace std;
using namespace filesystem;

path* getFiles(path);

int main(int argc, char **argv) {
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

	path p;

	switch (argv[1][1])
	{
	case 'd':
		cout << "MODE directory" << endl;
		p = path::path(argv[2]);
		if (is_directory(p))
		{
			cout << "[PASS] PATH : " << argv[2] << endl;
			path* filev = getFiles(p);
			free(filev);
		} else
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
	getchar();
	return 0;
}

path* getFiles(path p)
{
	directory_iterator it = directory_iterator::directory_iterator(p);
	list<string> supportedTypes {".bmp", ".pbm", ".pgm", ".ppm", ".sr", ".ras", ".jpeg", ".jpg", ".jpe", ".jp2", ".tiff", ".tif", ".png" };
	int filec = 0;
	for (auto& ptr : it) {
		if (std::find(supportedTypes.begin(), supportedTypes.end(), ptr.path().extension()) != supportedTypes.end()) {
			cout << "\t[  SUPPORTED  ] " << ptr.path().filename() << endl;
			++filec;
		}
		else {
			cout << "\t[NOT SUPPORTED] " << ptr.path().filename() << endl;
		}
	}
	path* filev = (path*) malloc(filec*sizeof(path));
	int i = 0;
	for (auto& ptr : directory_iterator::directory_iterator(p)) {
		if (std::find(supportedTypes.begin(), supportedTypes.end(), ptr.path().extension()) != supportedTypes.end()) {
			filev[i] = ptr.path();
			++i;
		}
	}
	return filev;
}
