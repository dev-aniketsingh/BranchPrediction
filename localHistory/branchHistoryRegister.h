#ifndef _BRANCHHISTORYREGISTER_H
#define	_BRANCHHISTORYREGISTER_H


#include <string>
using namespace std;

class BranchHistoryRegister {
  public:
        BranchHistoryRegister() {
          value = 0;
          size = 3;
          mask = size;
        }
        int getValue() {
          return value;
        }
        int getSize() {
          return size;
        }
        void setValue(int setValue) {
          value = setValue & mask;
        }
        void updateTaken() {
          value <<= 1;
          value += 1;
          value = value & mask;
        }
        void updateNotTaken() {
          value <<= 1;
          value = value & mask;
        }
        void updateBranchHistoryRegister(string takenBranch) {
          if(takenBranch == "T")
              updateTaken();
          else
              updateNotTaken();
        }

    private:
          int value;
          int size;
          int mask;
};

#endif
