#include <iostream>
#include <string>
#include <fstream>
#include <climits>
#include <cstdint>

#include "wave_header.h"

//stereo-16-bit.wav
//yes-8-bit-mono.wav
//yes-16-bit-mono.wav

int main(){
	wav_header header;
	sample value;

	//varaibles
	int sizeOfHeader = sizeof(wav_header), count = 0;
	
	int option;
	 
	const char* fileName;
	std::string input;
	
	//display menu
	start:
	std::cout << "---------------------" << std::endl;
	std::cout << "WAV START" << std::endl;
	std::cout << "---------------------" << std::endl;
	std::cout << "1. Start" << std::endl;
	std::cout << "2. Exit" << std::endl;
	std::cout << "Enter the corresponding number: " << std::endl;
	
	int i = 0;
	while(i == 0){
	std::cin >> option;
		if(option == 2){
			return 1;
		}
		else if(option == 1){
			std::cout<<"Enter filename: "<<std::endl;
			std::cin>>input;
			
			i++;
		}
		else{
			std::cout << "Enter an available choice" << std::endl;
		}
	}
	
	//read header data and determine if mono or stereo
    header = readHeader(input);
    if(header.num_channels == 1){
        std::cout << "Mono" << std::endl;
        // Wave<1, 8> wave("yes-8-bit-mono.wav");
    }
    else if(header.num_channels == 2){
        std::cout << "Stereo" << std::endl;
    }
    else{
        std::cout << "Not a valid wav file\n" << std::endl;
        goto start;
    }
    readFile(input);
    //Display file data
    std::cout<<"----------Data---------"<<std::endl;
    std::cout<<"File Name: "<<input<<std::endl;
    std::cout<<"Sampling Rate: "<<header.sample_rate<<"Hz"<<std::endl;
    std::cout<<"Type: "<<header.bit_depth<<"-bit file"<<std::endl;
    std::cout<<"Bytes of Data: "<<header.data_bytes<<std::endl;
    
    
    
    
    
    return 0;
}
