#ifndef __BIN_RENICE_H
#define __BIN_RENICE_H

#include <POSIXApplication.h>

/**
 * @addtogroup bin
 * @{
 */

/**
 * Change Priority Level of a process.
 */
class Renice : public POSIXApplication
{
  public:

    /**
     * Constructor
     *
     * @param argc Argument count
     * @param argv Argument values
     */
    Renice(int argc, char **argv);

    /**
     * Destructor
     */
    virtual ~Renice();

    /**
     * Execute the application.
     *
     * @return Result code
     */
    virtual Result exec();

};

/**
 * @}
 */

#endif /* __BIN_RENICE_H */
