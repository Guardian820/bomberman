//
// Created by romain on 29/05/18.
//

#ifndef CPP_INDIE_STUDIO_INETWORKCLIENTBUFFER_H
#define CPP_INDIE_STUDIO_INETWORKCLIENTBUFFER_H

#include <sys/types.h>

class ANetworkBuffer {
public:

    explicit ANetworkBuffer(size_t maxSize) : _position(0), _maxSize(maxSize) {};
    virtual ~ANetworkBuffer() = default;

    /**
     * Should Append to the buffer the given bytes
     *
     * @param bytes     bytes to push at the end of the buffer
     * @param length    n bytes to add
     * @return          true if the buffer size lower than the buffer max size, false otherwise
     */
    virtual bool append(char const *bytes, size_t length) = 0;
    virtual bool drop(size_t from, size_t to) = 0;
    virtual void clear() = 0;
    virtual char *getBytes() = 0;

    /**
     * Allocate more memory for the buffer
     *
     * @param bytes     number of bytes to add
     */
    virtual void allocate(size_t bytes) = 0;

    /**
     * Resize the buffer size.
     *
     * @param bytes     new bytes number capacity of the buffer
     */
    virtual void resize(size_t bytes) = 0;
    virtual size_t getSize() const = 0;

    virtual size_t getPosition() const;
    virtual void setPosition(size_t position);
    virtual size_t getMaxSize() const;
    virtual bool empty();

protected:

    size_t _position;
    size_t _maxSize;
};


#endif //CPP_INDIE_STUDIO_INETWORKCLIENTBUFFER_H
