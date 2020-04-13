#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <conio.h> 
#include <dir.h> 
#include <process.h> 
#include <stdio.h> 

using namespace std;

int main()
{
    string in = "reviewed-movies.txt";
    ifstream input_file(in.c_str());

    if(input_file.is_open()){

        vector <string> movies;
        string m;
        while(!input_file.eof()){
            getline(input_file, m);
            movies.push_back(m);
        }

        string html_input = "", title = "", a;
        char c;
        int check = 0;
        for(vector <string>::iterator it = movies.begin(); it != movies.end(); it++){
            // cout << "Generating " << *it << " directory..." << endl;
            // title = "img/" + *it;
            // check = mkdir(title.c_str());
            // if(check) {cout << "Directory Made Succesfully!" << endl;}
            // else {cout << "Directory Generation Failed." << endl;}

            cout << "Generating " << *it << ".html file..." << endl;
            m = "review-pages/" + *it + ".html";
            title = *it;
            c = title[0] - 32;
            a = c;
            title = title.replace(0, 1, a);
            size_t pos = title.find("-");
            while(pos != string::npos){
                title = title.replace(pos,1," ");
                c = title[pos + 1] - 32;
                a = c;
                title = title.replace(pos + 1, 1, "" + a);
                pos = title.find("-");
            }
            ofstream output_file(m.c_str());
            string info = "movie-info/" + *it + ".txt", synopsis = "";
            ifstream info_file(info.c_str());
            getline(info_file, synopsis);
            html_input = "<!DOCTYPE html><html lang='en'><head><meta charset='UTF-8'><meta name='viewport' content='width=device-width, initial-scale=1.0'><link rel='stylesheet' href='../main.css'><meta name='description' content='Review of " + title + "'><meta name='keywords' content='Movie Reviews,Movies,Reviews,Films," + title + "'><meta name='author' content='Josh Solomon'><title>" + title + " Review</title><style>#header {height: 200px;}#header h1 {line-height: 200px;margin: 0px;padding: 0px;}#content p{font-size: 1.2rem;}#content h3 {text-align: center;font-size: 1.2rem;}</style></head><body><div id='header'><h1>A Hint of Cinema</h1></div><div id='navbar'><a href='../main.html'>Movies</a><a href='../about.html'>About</a><a href='../reccomendations.html'>Recommendations</a></div><div id='content'><h2>" + title + "</h2><div class='synopsis'><h3>Synopsis</h3><p>" + synopsis + "</p></div><div class='pictures'><h3>Gallery</h3><img class='single-item' src='../img/" + *it + "/img1.jpg' alt='Image 1'><img class='single-item' src='../img/" + *it + "/img2.jpg' alt='Image 2'><img class='single-item' src='../img/" + *it + "/img3.jpg' alt='Image 3'><a class='prev' onclick='plusSlides(-1)'>PREV</a><a class='next' onclick='plusSlides(1)'>NEXT</a></div><div class='review'><h3>Review</h3></div></div><div id='footer'>Reviews and Website Design by Josh Solomon &COPY;2020</div><script src='../slideshow.js'></script></body></html>";
            info_file.close();
            output_file << html_input;
            output_file.close();
            cout << "Output File Generated" << endl;
        }

        input_file.close();
    }
}