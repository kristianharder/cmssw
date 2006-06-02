#ifndef DetLayers_MuDetRing_H
#define DetLayers_MuDetRing_H

/** \class MuDetRing
 *  A ring of periodic, possibly overlapping vertical detectors.
 *  Designed for forward muon CSC/RPC chambers.
 *
 *  $Date: 2006/06/01 16:47:05 $
 *  $Revision: 1.2 $
 *  \author N. Amapane - INFN Torino
 */

#include "TrackingTools/DetLayers/interface/ForwardDetRingOneZ.h"
#include "Utilities/BinningTools/interface/PeriodicBinFinderInPhi.h"

class GeomDet;

class MuDetRing : public ForwardDetRingOneZ {
 public:

  /// Construct from iterators on GeomDet*
  MuDetRing(std::vector<const GeomDet*>::const_iterator first,
	    std::vector<const GeomDet*>::const_iterator last);

  /// Construct from a vector of GeomDet*
  MuDetRing(const std::vector<const GeomDet*>& dets);

  virtual ~MuDetRing();


  // GeometricSearchDet interface

  virtual const std::vector<const GeometricSearchDet*>& components() const;

  virtual pair<bool, TrajectoryStateOnSurface>
  compatible( const TrajectoryStateOnSurface& ts, const Propagator& prop, 
	      const MeasurementEstimator& est) const;

  virtual std::vector<DetWithState> 
  compatibleDets( const TrajectoryStateOnSurface& startingState,
		  const Propagator& prop, 
		  const MeasurementEstimator& est) const;

  virtual std::vector<DetGroup> 
  groupedCompatibleDets( const TrajectoryStateOnSurface& startingState,
			 const Propagator& prop,
			 const MeasurementEstimator& est) const;


  // FIXME: should be implemented (overlaps in forward CSC and RPC)
  virtual bool hasGroups() const {return false;}

 private:
  typedef PeriodicBinFinderInPhi<float>   BinFinderType;
  BinFinderType theBinFinder;

  void init();

};
#endif

