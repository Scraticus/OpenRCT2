/*****************************************************************************
 * Copyright (c) 2014-2024 OpenRCT2 developers
 *
 * For a complete list of all authors, please refer to contributors.md
 * Interested in contributing? Visit https://github.com/OpenRCT2/OpenRCT2
 *
 * OpenRCT2 is licensed under the GNU General Public License version 3.
 *****************************************************************************/

#include "MazeCost.h"

#include "../core/Money.hpp"
#include "../world/Location.hpp"
#include "Ride.h"
#include "RideData.h"
#include "TrackData.h"

using namespace OpenRCT2::TrackMetaData;

namespace OpenRCT2
{
    money64 MazeCalculateCost(money64 constructionCost, const Ride& ride, const CoordsXYZ& loc)
    {
        const auto& ted = GetTrackElementDescriptor(TrackElemType::Maze);
        money64 price = (ride.GetRideTypeDescriptor().BuildCosts.TrackPrice * ted.PriceModifier) >> 16;

        auto surfaceElement = MapGetSurfaceElementAt(loc);
        auto heightDifference = (loc.z - surfaceElement->GetBaseZ()) / kCoordsZPerTinyZ;
        money64 supportCost = heightDifference * ride.GetRideTypeDescriptor().BuildCosts.SupportPrice;

        return constructionCost + price + supportCost;
    }
} // namespace OpenRCT2
