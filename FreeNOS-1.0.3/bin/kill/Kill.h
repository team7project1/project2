#ifndef __BIN_KILL_H
#define __BIN_KILL_H

#include <POSIXApplication.h>

/**
 * @addtogroup bin
 * @{
 */

/**
 * Kill a process.
 */
class Kill : public POSIXApplication
{
  public:

    /**
     * Constructor
     *
     * @param argc Argument count
     * @param argv Argument values
     */
    Kill(int argc, char **argv);

    /**
     * Destructor
     */
    virtual ~Kill();

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

#endif /* __BIN_KILL_H */
