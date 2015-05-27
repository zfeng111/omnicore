#ifndef OMNICORE_PENDING_H
#define OMNICORE_PENDING_H

class uint256;
class CMPPending;

#include <stdint.h>
#include <map>
#include <string>

namespace mastercore
{
//! Map of pending transaction objects
typedef std::map<uint256, CMPPending> PendingMap;
//! Global map of pending transaction objects
extern PendingMap my_pending;

/** Adds a transaction to the pending map using supplied parameters. */
void PendingAdd(const uint256& txid, const std::string& sendingAddress, const std::string& refAddress, uint16_t type, uint32_t propertyId, int64_t amount, uint32_t propertyIdDesired = 0, int64_t amountDesired = 0, int64_t action = 0);

/** Deletes a transaction from the pending map and credits the amount back to the pending tally for the address. */
void PendingDelete(const uint256& txid);
}

/** Structure to hold information about pending transactions.
 */
struct CMPPending
{
    std::string src;  // the source address
    uint32_t prop;
    int64_t amount;
    uint32_t type;
    std::string desc; // the description

    /** Default constructor. */
    CMPPending() : prop(0), amount(0), type(0) {};

    /** Prints information about a pending transaction object. */
    void print(const uint256& txid) const;
};


#endif // OMNICORE_PENDING_H
