#include <exception>
#include <iostream>

#include "TString.h"


class Sample {
public:
  static std::vector<TString> fileNameFullSample();
};


std::vector<TString> Sample::fileNameFullSample() {
  TString path_ = "/afs/hep.wisc.edu/cms/khurana/Script/AnalysisTuples_V53/";
  std::vector<TString> nameVec;
  TString name("");

  name = path_ + "Merged_MonoHToBBarMZp-600GeV_MA0-300GeV-runallAnalysis.root";  nameVec.push_back(name);
  name = path_ + "Merged_MonoHToBBarMZp-800GeV_MA0-300GeV-runallAnalysis.root";  nameVec.push_back(name);
  name = path_ + "Merged_MonoHToBBarMZp-1000GeV_MA0-300GeV-runallAnalysis.root";  nameVec.push_back(name);
  name = path_ + "Merged_MonoHToBBarMZp-1200GeV_MA0-300GeV-runallAnalysis.root";  nameVec.push_back(name);
  name = path_ + "Merged_MonoHToBBarMZp-1400GeV_MA0-300GeV-runallAnalysis.root";  nameVec.push_back(name);
  name = path_ + "Merged_MonoHToBBarMZp-1700GeV_MA0-300GeV-runallAnalysis.root";  nameVec.push_back(name);
  name = path_ + "Merged_MonoHToBBarMZp-2000GeV_MA0-300GeV-runallAnalysis.root";  nameVec.push_back(name);
  name = path_ + "Merged_MonoHToBBarMZp-2500GeV_MA0-300GeV-runallAnalysis.root";  nameVec.push_back(name);
  
  name = path_ + "Merged_ST_s-channel_4f_leptonDecays_13TeV-amcatnlo-pythia8_TuneCUETP8M1-runallAnalysis.root";  nameVec.push_back(name);
  name = path_ + "Merged_ST_t-channel_antitop_4f_leptonDecays_13TeV-powheg-pythia8_TuneCUETP8M1-runallAnalysis.root";  nameVec.push_back(name);
  name = path_ + "Merged_ST_t-channel_top_4f_leptonDecays_13TeV-powheg-pythia8_TuneCUETP8M1-runallAnalysis.root";  nameVec.push_back(name);
  name = path_ + "Merged_ST_tW_antitop_5f_inclusiveDecays_13TeV-powheg-pythia8_TuneCUETP8M1-runallAnalysis.root";  nameVec.push_back(name);
  name = path_ + "Merged_ST_tW_top_5f_inclusiveDecays_13TeV-powheg-pythia8_TuneCUETP8M1-runallAnalysis.root";  nameVec.push_back(name);
  
  name = path_ + "Merged_TT_TuneCUETP8M1_13TeV-powheg-pythia8-runallAnalysis.root";  nameVec.push_back(name);
  
  name = path_ + "Merged_WJetsToLNu_HT-100To200_TuneCUETP8M1_13TeV-madgraphMLM-pythia8-runallAnalysis.root";  nameVec.push_back(name);
  name = path_ + "Merged_WJetsToLNu_HT-1200To2500_TuneCUETP8M1_13TeV-madgraphMLM-pythia8-runallAnalysis.root";  nameVec.push_back(name);
  name = path_ + "Merged_WJetsToLNu_HT-200To400_TuneCUETP8M1_13TeV-madgraphMLM-pythia8-runallAnalysis.root";  nameVec.push_back(name);
  name = path_ + "Merged_WJetsToLNu_HT-2500ToInf_TuneCUETP8M1_13TeV-madgraphMLM-pythia8-runallAnalysis.root";  nameVec.push_back(name);
  name = path_ + "Merged_WJetsToLNu_HT-400To600_TuneCUETP8M1_13TeV-madgraphMLM-pythia8-runallAnalysis.root";  nameVec.push_back(name);
  name = path_ + "Merged_WJetsToLNu_HT-600To800_TuneCUETP8M1_13TeV-madgraphMLM-pythia8-runallAnalysis.root";  nameVec.push_back(name);
  name = path_ + "Merged_WJetsToLNu_HT-800To1200_TuneCUETP8M1_13TeV-madgraphMLM-pythia8-runallAnalysis.root";  nameVec.push_back(name);
  
  name = path_ + "Merged_WW_TuneCUETP8M1_13TeV-pythia8-runallAnalysis.root";  nameVec.push_back(name);
  name = path_ + "Merged_WZ_TuneCUETP8M1_13TeV-pythia8-runallAnalysis.root";  nameVec.push_back(name);
  name = path_ + "Merged_ZH_HToBB_ZToNuNu_M120_13TeV_amcatnloFXFX_madspin_pythia8-runallAnalysis.root";  nameVec.push_back(name);
  
  name = path_ + "Merged_ZJetsToNuNu_HT-100To200_13TeV-madgraph-runallAnalysis.root";  nameVec.push_back(name);
  name = path_ + "Merged_ZJetsToNuNu_HT-200To400_13TeV-madgraph-runallAnalysis.root";  nameVec.push_back(name);
  name = path_ + "Merged_ZJetsToNuNu_HT-400To600_13TeV-madgraph-runallAnalysis.root";  nameVec.push_back(name);
  name = path_ + "Merged_ZJetsToNuNu_HT-600ToInf_13TeV-madgraph-runallAnalysis.root";  nameVec.push_back(name);
  
  name = path_ + "Merged_ZZ_TuneCUETP8M1_13TeV-pythia8-runallAnalysis.root";  nameVec.push_back(name);
  
  name = path_ + "Merged_crab_MET-Run2015C_25ns-05Oct2015V120160203_FullDataSet_2p2FB_SkipEventsOldFile29Oct-runallAnalysis.root";  nameVec.push_back(name);
  name = path_ + "Merged_crab_MET-Run2015D-05Oct2015V120160203_FullDataSet_2p2FB_SkipEventsOldFile29Oct-runallAnalysis.root";  nameVec.push_back(name);
  name = path_ + "Merged_crab_MET-Run2015D-PromptReco-V420160203_FullDataSet_2p2FB_SkipEventsOldFile29Oct-runallAnalysis.root";  nameVec.push_back(name);
  
  name = path_ + "Merged_ggZH_HToBB_ZToNuNu_M120_13TeV_powheg_pythia8-runallAnalysis.root";  nameVec.push_back(name);
  name = path_ + "Merged_MET.root";  nameVec.push_back(name);

 return nameVec;

 }
