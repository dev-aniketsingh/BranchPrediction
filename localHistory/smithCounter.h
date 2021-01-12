#ifndef _SMITHCOUNTER_H
#define	_SMITHCOUNTER_H

#include<string>

class SmithCounter {
    private:
        int prediction;
    public:
        SmithCounter() {
          prediction = 0;
        }
        bool getPrediction() {
          return prediction >> 1;
        }
        void updatePrediction(std::string takenBranch) {
          if(takenBranch == "T" and prediction < 3)
              prediction++;
          else if(prediction > 0)
              prediction--;
        }
};

#endif //_SMITHCOUNTER_H
