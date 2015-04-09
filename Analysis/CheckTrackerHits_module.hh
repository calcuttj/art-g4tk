//
//               __        __ __  __  __  
//   ____ ______/ /_____ _/ // / / /_/ /__
//  / __ `/ ___/ __/ __ `/ // /_/ __/ //_/
// / /_/ / /  / /_/ /_/ /__  __/ /_/ ,<   
// \__,_/_/   \__/\__, /  /_/  \__/_/|_|  
//               /____/                  
//
// artg4tk: art based Geant 4 Toolkit
// 
//=============================================================================
// CheckHits_module.hh: Analyzer module that demonstrates access to hits 
// and makes some histograms
// 
// Author: Hans Wenzel (Fermilab)
//=============================================================================
#ifndef CHECKHITS_MODULE_HH
#define	CHECKHITS_MODULE_HH
// art Framework includes.
#include "art/Framework/Core/EDAnalyzer.h"
#include "art/Framework/Principal/Event.h"
#include "art/Framework/Principal/Handle.h"
#include "art/Framework/Services/Optional/TFileService.h"
#include "art/Framework/Core/ModuleMacros.h"
#include "art/Framework/Principal/Run.h"
#include "art/Framework/Services/Optional/TFileDirectory.h"
#include "art/Framework/Services/Registry/ServiceHandle.h"
#include "art/Framework/Principal/Provenance.h"
// artg4 includes:
#include "artg4tk/services/DetectorHolder_service.hh"
// artg4tk includes:
#include "artg4tk/pluginDetectors/gdml/myCaloArtHitData.hh"
#include "artg4tk/pluginDetectors/gdml/myDRCaloArtHitData.hh"
#include "artg4tk/pluginDetectors/gdml/myParticleEContribArtData.hh"
#include "artg4tk/pluginDetectors/gdml/myTrackerArtHitData.hh"
// Root includes.
#include "TFile.h"
#include "TH1F.h"
#include "TH2F.h"
#include "TDirectory.h"
// Other includes.
#include "CLHEP/Units/SystemOfUnits.h"

using namespace std;
namespace artg4tk {
    class CheckTrackerHits;
}

class artg4tk::CheckTrackerHits : public art::EDAnalyzer {
public:

    explicit CheckTrackerHits(fhicl::ParameterSet const& p);
    virtual void beginJob();
    virtual void beginRun(const art::Run& Run);
    virtual void endJob();
    virtual void analyze(const art::Event& event);

private:


  TH1F* _hnHits; // number of TrackerHits
  TH1F* _hEdep; // total energy deposition 
  TH1F* _hrEdep; // radius of Energy deposition
  TH1F* _hzEdep;//   z  position of Energy deposition
};

#endif	/* CHECKHITS_MODULE_HH */

