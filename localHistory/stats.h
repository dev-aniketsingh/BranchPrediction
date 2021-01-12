#ifndef _STATS_H
#define	_STATS_H

class Stats  {
    private:
        int branches;
        int btCount;
        int correctPTB;
        int bNTCount;
        int correctPNTB;
    public:
        Stats() {
          branches = 0;
          btCount = 0;
          correctPTB = 0;
          bNTCount = 0;
          correctPNTB = 0;
        }
        void incrementBranches() {
          branches++;
        }
        int getBranches() {
          return branches;
        }
        void incrementbtCount() {
          btCount++;
        }
        int getbtCount() {
          return btCount;
        }
        void incrementcorrectPTB() {
          correctPTB++;
        }
        int getcorrectPTB() {
          return correctPTB;
        }
        void incrementbNTCount() {
          bNTCount++;
        }
        int getbNTCount() {
          return bNTCount;
        }
        void incrementcorrectPNTB() {
          correctPNTB++;
        }
        int getcorrectPNTB() {
          return correctPNTB;
        }
        double getPercent() {
          return ((double)(correctPTB + correctPNTB)/(double)branches) * 100;
        }
};

#endif // _STATS_H
