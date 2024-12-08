#include "PointSet.hh"
#include "PointTypes.hh"
#include "SubTree.hh"
#include "Utils.hh"

using namespace EMST;
using namespace CyA;

int main(int argc, char *argv[]) {
  if (argc != 2) {
    std::cerr << "Usage: " << argv[0] << " <input_file>" << std::endl;
    return 1;
  }

  point_vector points;
  if (!read_points(argv[1], points)) {
    std::cerr << "Error reading points from file " << argv[1] << std::endl;
    return 2;
  }

  point_set ps(points);
  ps.EMST();
  ps.write_tree(std::cout);

  return 0;
}