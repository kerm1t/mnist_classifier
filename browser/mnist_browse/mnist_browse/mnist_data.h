#pragma once

#include <string>
#include <vector>

class mnist_data
{
public:
  UINT32 num_img;
  UINT32 num_rows;
  UINT32 num_columns;
  mnist_data();
  ~mnist_data();

  std::string load_fast(const char *filename);
  void load(std::string filename, std::vector<unsigned char> buf);
};
