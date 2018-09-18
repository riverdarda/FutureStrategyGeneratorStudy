// Standard Library
#include <iostream>
#include <fstream>
#include "boost/algorithm/string.hpp"
#include "boost/filesystem.hpp"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <cstdio>
#include <memory>
#include <stdexcept>
#include <string>
#include <array>

// ROOT
#include "TFile.h"
#include "TTree.h"
#include "TH1.h"
#include "TH2.h"
#include "TCanvas.h"
#include "TLine.h"
#include "TText.h"
#include "TROOT.h"
#include "TStyle.h"
#include "TVector3.h"
#include "TDictionary.h"
#include "TBranch.h"
#include "TLegend.h"
#include "TPaveText.h"
#include "TLatex.h"
#include "TF1.h"
#include "TRandom3.h"
#include "TLimit.h"
#include "TConfidenceLevel.h"
#include "TLimitDataSource.h"

using namespace std;

string treeName="SimData";

// 6 walls for the calorimeters, the order matters
enum ISOTOPE  {SE82, ND150};
string ISOTOPE_LATEX[2] = {"^{82}Se","^{150}Nd"};
string ISOTOPE_NAME[2] = {"Se82","Nd150"};
double Qbb[2] = {2.99,3.368};
string FILES2NU[2]={"/Users/cpatrick/uclnemo3/generatorstudy/se82/2nubb/Se82_2nubb_1E8_flsim_1.root","/Users/cpatrick/uclnemo3/generatorstudy/nd150/run_1/Nd150_2nubb_1E6_flsim_1_trimmed.root"};
string FILES0NU[2]={"/Users/cpatrick/uclnemo3/generatorstudy/se82/0nubb/Se82_0nubb_1E8_flsim_1.root"," /Users/cpatrick/uclnemo3/generatorstudy/nd150/nd150_0nu/1e5/run_1/Nd150_0nubb_1E6_flsim_1.root"};
double FRAC_OVER_2MEV[2]={1,0.0982};
int TLIMIT_EXPERIMENTS=50000; // Number of pesudoexperiments to run for limit calculation

int main(int argc, char **argv);
void Analyze(ISOTOPE isotope, double resolutionAt1MeV);
double Smear(double energy, double smearCoefficient);
TH1D * makeSmearedHistogram(ISOTOPE isotope, bool is2nu, double resolutionAt1MeV);
TH1D * FAKESmearedHistogram(ISOTOPE isotope, double resolutionAt1MeV);
//double EstimateBackgroundEvents(double backgroundEfficiency, double isotopeMass, double molarMass, double halfLife);
double ExpectedLimitSigEvts(double ConfidenceLevel, TH1D* h_signal, TH1D* h_background, TH1D* h_data );
