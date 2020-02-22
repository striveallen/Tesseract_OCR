#include<iostream>
#include <stdio.h>
#include<windows.h>
#include "allheaders.h"
#include "tesseract/capi.h"
#include<fstream>


using namespace std;


void die(const char *errstr) {
	fputs(errstr, stderr);
	exit(1);
}


void ConvertUtf8ToGBK(char **amp, char *strUtf8)  //◊™¬Î
{
	int len = MultiByteToWideChar(CP_UTF8, 0, (LPCSTR)strUtf8, -1, NULL, 0);
	unsigned short * wszGBK = new unsigned short[len + 1];
	memset(wszGBK, 0, len * 2 + 2);
	MultiByteToWideChar(CP_UTF8, 0, (LPCSTR)strUtf8, -1, (LPWSTR)wszGBK, len);
	len = WideCharToMultiByte(CP_ACP, 0, (LPCWSTR)wszGBK, -1, NULL, 0, NULL, NULL);
	//char *szGBK=new char[len + 1]; 
	*amp = new char[len + 1];
	memset(*amp, 0, len + 1);
	WideCharToMultiByte(CP_ACP, 0, (LPCWSTR)wszGBK, -1, *amp, len, NULL, NULL);
}

int main(int argc, char *argv[]) {
	TessBaseAPI *handle;
	PIX *img;
	char *text = NULL;

	//Read the image according to the path of the image
	if ((img = pixRead("11.jpg")) == NULL)
		die("Error reading image\n");

	handle = TessBaseAPICreate();
	//º”‘ÿ◊÷ø‚º∞…Ë÷√”Ô—‘
	if (TessBaseAPIInit3(handle, "./tessdata", "eng+chi_sim") != 0)
		die("Error initialising tesseract\n");

	//Load the font base and set the language
	TessBaseAPISetImage2(handle, img);
	if (TessBaseAPIRecognize(handle, NULL) != 0)
		die("Error in Tesseract recognition\n");

	if ((text = TessBaseAPIGetUTF8Text(handle)) == NULL)
		die("Error getting text\n");

	char *pResult = NULL;
	//Transcode the result
	ConvertUtf8ToGBK(&pResult, text); 

	//Output OCR recognized information of the text 
	cout << pResult << endl;   



	//Create a file output stream object
	ofstream os;    

	//Associate an object with a file
	os.open("result.txt");

	
	//Put the input into the TXT file
	os << pResult;  
	os.close();

	


	system("pause");

	//free the memory
	delete pResult;
	TessDeleteText(text);
	TessBaseAPIEnd(handle);
	TessBaseAPIDelete(handle);
	pixDestroy(&img);

	return 0;
}
