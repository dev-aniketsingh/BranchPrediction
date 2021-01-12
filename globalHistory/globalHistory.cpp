#include "smithCounter.h"
#include "stats.h"
#include "branchHistoryRegister.h"
#include <iostream>
#include <iomanip>
#include <istream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>


using namespace std;

int main() {

	Stats smith_stats;
	SmithCounter smith_array[128];
	BranchHistoryRegister bhr;

	string branch;
	string pathIdentifier;
	int instruction;
	bool pathPrediction;
	bool takenPath;

	ifstream input("branch_trace.dat");


	while (getline(input,branch,' '))
   {
	   if(input.eof())
	   {
		   break;
	   }

	   getline(input,pathIdentifier,'\n');
	   instruction = atoi(branch.c_str());
	   int index = (((instruction/4) << (bhr.getSize())) | (bhr.getValue() & 0x7)) & 0x7F;
	   pathPrediction = smith_array[index].getPrediction();

	   if (pathIdentifier.find('T') != std::string::npos)
	   {
		   takenPath=true;
		   smith_stats.incrementbtCount();
	   }
	   else if (pathIdentifier.find('N') != std::string::npos)
	   {
		   takenPath=false;
		   smith_stats.incrementbNTCount();
	   }

	   if (pathPrediction && takenPath)
	   {
		   smith_array[index].updatePrediction(pathIdentifier);
		   bhr.updateBranchHistoryRegister(pathIdentifier);
		   smith_stats.incrementcorrectPTB();

	   }
	   else if (pathPrediction && !takenPath)
	   {
		   smith_array[index].updatePrediction(pathIdentifier);
		   bhr.updateBranchHistoryRegister(pathIdentifier);
	   }
	   else if (!pathPrediction && !takenPath)
	   {
		   smith_array[index].updatePrediction(pathIdentifier);
		   bhr.updateBranchHistoryRegister(pathIdentifier);
		   smith_stats.incrementcorrectPNTB();
	   }
	   else if (!pathPrediction && takenPath)
	   {
		   smith_array[index].updatePrediction(pathIdentifier);
		   bhr.updateBranchHistoryRegister(pathIdentifier);
	   }

		smith_stats.incrementBranches();
	}

	input.close();

	cout << "Number of branches: " << smith_stats.getBranches() << endl;
	cout << "Number of branches taken: " << smith_stats.getbtCount() << endl;
	cout << "Number taken branches correctly predicted: " << smith_stats.getcorrectPTB() << endl;
	cout << "Number of branches not taken: " << smith_stats.getbNTCount() << std::endl;
	cout << "Number not taken branches correctly predicted: " << smith_stats.getcorrectPNTB() << endl;
	cout << "Overall rate of correct predictions: " << smith_stats.getPercent() << "%" << endl;

	return 0;
}
