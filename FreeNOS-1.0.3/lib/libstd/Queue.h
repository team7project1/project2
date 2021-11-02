/*
 * Copyright (C) 2019 Niek Linnenbank
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef __LIBSTD_QUEUE_H
#define __LIBSTD_QUEUE_H

#include "Types.h"
#include "Macros.h"
#include "Container.h"

/**
 * @addtogroup lib
 * @{
 *
 * @addtogroup libstd
 * @{
 */

/**
 * Array of items as a First-In-First-Out (FIFO) datastructure.
 */
template <class T, Size N> class Queue : public Container
{
  public:

    /**
     * Default constructor
     */
    Queue()
    {
        clear();
    }

    /**
     * Add item to the head of the Queue.
     *
     * @param item The item to add
     *
     * @return True if successful, false otherwise
     */
    bool push(const T & item)
    {
        if (m_count >= N)
        {
            return false;
        }

        m_array[m_head] = item;
        m_head = (m_head + 1) % N;
        m_count++;

        return true;
    }

    /**
     * Remove item from the tail of the Queue.
     *
     * @return Item T
     *
     * @note Do not call this function if the Queue is empty
     */
    T & pop()
    {
        uint idx = m_tail;
        m_tail = (m_tail + 1) % N;
        m_count--;

        return m_array[idx];
    }

    /**
     * Look if an item exists on the Queue
     *
     * @param item Item reference
     *
     * @return True if the item exists, false otherwise
     */
    bool contains(const T & item) const
    {
        for (Size i = 0; i < m_count; i++)
        {
            if (m_array[(m_tail + i) % N] == item)
                return true;
        }

        return false;
    }
    
    /* 
    *  Helper function for QuickSort algorithm. Sections off parts of the queue array
    *
    * @param left: integer representing the leftmost index of the array to be partitioned.
    *
    * @param right: integer representing the rightmost index of the array to be partitioned.
    * 
    * @return unsigned int of the pivot index.
    */
    uint partition(uint left, uint right)
    {
    	PriorityLevel right_index = m_array[right]->getPriority();
    	uint current_index = left - 1;
    	
    	for (uint j = left; j < right; j++) {
    	       if(m_array[j]->getPriority() >= right_index) 
    	       {
    	          current_index++;
    	          T temp = m_array[current_index];
		  m_array[current_index] = m_array[j];
		  m_array[j] = temp;
    	       }   
    	}
        T temp = m_array[current_index + 1];
    	m_array[current_index + 1] = m_array[right];
    	m_array[right] = temp;
    	return current_index + 1;
    }
    
     /**
     * Uses standard QuickSort Algorithm to sort the array in Descending Order.
     *
     * @param left: integer representing the leftmost index of the array to be sorted.
     *
     * @param right: integer representing the rightmost index of the array to be sorted.
     *
     */
    void quickSort(uint left, uint right) 
    {
      	if ((left < right) && (left >= 0 && right >= 0)) {
    	
    		uint section_index = partition(left, right);
    		
    		// Recursively iterate over the partition sections.
    		quickSort(left, section_index - 1);
    		quickSort(section_index + 1, right);
    		
    	} 
    }
    
    
    // Perform sorting using QuickSort function.
    void sortQueue() {
    	 uint i = m_tail;
         while((m_tail >= 0 && m_head > 0) && m_count != 0 && i < m_head)  {
         	for(uint j=i+1; j < m_head; j++) {
         		if(m_array[i]->getPriority() < m_array[j]->getPriority()) {
         			T temp = m_array[i];
         			m_array[i] = m_array[j];
         			m_array[j] = temp;
         		}
         	}
         	i++;
         }
    }
    
    /**
     * Remove all items with the given value.
     *
     * @param value Value to remove.
     *
     * @return Number of items removed.
     */
    Size remove(T value)
    {
        const Size numItems = m_count;
        Size numRemoved = 0;

        for (Size i = 0; i < numItems; i++)
        {
            T & item = pop();

            if (item != value)
                push(item);
            else
                numRemoved++;
        }

        return numRemoved;
    }

    /**
     * Removes all items from the Queue.
     */
    virtual void clear()
    {
        m_head = 0;
        m_tail = 0;
        m_count = 0;
    }

    /**
     * Returns the maximum size of this Queue.
     *
     * @return size The maximum size of the Queue.
     */
    virtual Size size() const
    {
        return N;
    }

    /**
     * Returns the number of items in the Queue.
     *
     * @return Number of items in the Queue.
     */
    virtual Size count() const
    {
        return m_count;
    }

  private:

    /** The actual array where the data is stored. */
    T m_array[N];

    /** Head of the queue */
    uint m_head;

    /** Tail of the queue */
    uint m_tail;

    /** Number of items in the queue */
    uint m_count;
};

/**
 * @}
 * @}
 */

#endif /* __LIBSTD_QUEUE_H */
