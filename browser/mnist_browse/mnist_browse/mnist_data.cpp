#include "stdafx.h"
#include "mnist_data.h"

#include <fstream>
#include <iterator>
#include <vector>
#include <string>
#include <cerrno>
#include "assert.h"

mnist_data::mnist_data()
{
}
mnist_data::~mnist_data()
{
}

// http://insanecoding.blogspot.com/2011/11/how-to-read-in-file-in-c.html

std::string mnist_data::load_fast(const char *filename)
{
  std::ifstream in(filename, std::ios::in | std::ios::binary);
  if (in)
  {
    std::string contents;
    in.seekg(0, std::ios::end);
    contents.resize(in.tellg());
    in.seekg(0, std::ios::beg);
    in.read(&contents[0], contents.size());
    in.close();
    const char * testCharArray = contents.c_str(); 
    
    int num     = (contents[2] << 8) | contents[3];
    assert(num == 2051, "magic number mismatch");
    int i = 256 + contents[6] % 255;  // -22 --> 234
    int j = contents[7];
    num_img = (i << 8) | j;
    num_columns = contents[15];
    num_rows    = contents[11];

    return(contents);
  }
  throw(errno);
}

void mnist_data::load(std::string filename, std::vector<unsigned char> buf)
{
  std::ifstream input(filename, std::ios::binary);

  // copies all data into buffer
//  buf(std::istreambuf_iterator<char>(input), {});
  std::vector<unsigned char> buffer(std::istreambuf_iterator<char>(input), {});
}
