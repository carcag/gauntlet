#ifndef FINDFILE_HPP_
#define FINDFILE_HPP_

#include <cstdio>
#include <cstring>
#include <sstream>

template<typename T>
void saveInfoInFile(const char path[], T & Data )
{
  std::ostringstream oss;
  oss << Data;
  std::string sparam = oss.str();
  FILE* file = fopen(path, "r");

  if(file == NULL)
    {
      file = fopen(path, "a");
      rewind(file);
      fprintf(file,"%s\n", sparam.c_str());
      fclose(file);
    }
  else
    {
      std::string pathTemp = path;
      pathTemp+= "Temp";
      FILE *fileTemp = fopen(pathTemp.c_str(), "w+");

      char line[256];
      bool info = false;
      bool check = true;

      while(check) {
	         if(fgets(line, 255, file) != NULL)
	           fprintf(fileTemp, "%s",line);
	         else {
	           if(!info) {
                fprintf(fileTemp, "%s\n", sparam.c_str());
              }
	           check = false;
            }
      }
    fclose(file);
    remove(path);
    rewind(fileTemp);
    file = fopen(path, "w");
    check = true;
    while(check) {
	     if(fgets(line, 255, fileTemp) != NULL) {
          fprintf(file, "%s",line);
       }
	    else {
        check = false;
      }
    }
  fclose(file);
  fclose(fileTemp);
  remove(pathTemp.c_str());
  }
}

#endif  //FINDFILE_HPP_
