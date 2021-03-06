/*
* Pegasus Engine
* 2017 - Benjamin Carter (bencarterdev@outlook.com)
*
* This software is provided 'as-is', without any express or implied warranty.
* In no event will the authors be held liable for any damages arising from the use of this software.
*
* Permission is granted to anyone to use this software for any purpose,
* including commercial applications, and to alter it and redistribute it freely,
* subject to the following restrictions:
*
* 1. The origin of this software must not be misrepresented;
*    you must not claim that you wrote the original software.
*    If you use this software in a product, an acknowledgement
*    in the product documentation would be appreciated but is not required.
*
* 2. Altered source versions must be plainly marked as such,
*    and must not be misrepresented as being the original software.
*
* 3. This notice may not be removed or altered from any source distribution.
*/

#ifndef _PEGASUS_RESOURCES_HPP_
#define _PEGASUS_RESOURCES_HPP_

//==================== 
// C++ includes
//==================== 
#include <unordered_map> // Stores all of the resources and their locations.
#include <memory>        // The serializable service is a smart pointer.
#include <string>        // Stores the key and value of the resources.

//==================== 
// Pegasus includes
//==================== 
#include <pegasus/core/resource.hpp>                   // A struct representing a single resource.
#include <pegasus/utilities/iserializable_service.hpp> // De-serializing the resources into a format the engine can use.

namespace pegasus
{   
    /**
     * @author Benjamin Carter
     * 
     * @class pegasus::Resources
     * @ingroup core
     *
     * @brief Loads and stores the file locations for all resources within the
     * pegasus engine.
     *
     * The Resources class is a static class that is used to store the file
     * locations of all resources used within the Pegasus Engine. The resources
     * are defined within the Resources.xml file, which maps a simple name to a
     * more complex file location.
     *
     * This class aids in retrieving resources from the ResourceManager with a
     * simpler naming convention that will not have to rely on hard-coded file
     * directories for caching and retrieval of assets.
     */
    class Resources final
    {
    private:
        //==================== 
        // Member variables
        //==================== 
        /** Stores all of the file locations of the defined resources.*/
        static std::unordered_map<std::string, Resource_t> m_resources;
		/** The unique serializable service type assigned to de-serialize the Resources file. */
		static ISerializableService* m_pService;

    public:
        //==================== 
        // Ctors and dtor
        //==================== 
        /**
         * @brief Default constructor.
         */
        explicit Resources() = default;

        /**
         * @brief Default destructor.
         */
        ~Resources() = default;

        //==================== 
        // Getters and setters
        //==================== 
		/**
		 * @brief Sets the serializable service for the Resources object.
		 *
		 * The serializable service is responsible for the method in which the resources
		 * file will be de-serialized into a format that the pegasus engine can utilise. 
		 * The serialization type is declared within the pegasus initialisation file under the
		 * [Serialization] header.
		 *
		 * @param service The object that the service should be set to.
		 */
		 void setService(ISerializableService& service);

        /**
         * @brief Retrieves a resource object from the map.
         *
         * When a resource is requested, it will utilitise the loaded
         * Resoures.xxx file and search for the specified name. If the name is
         * found it will return the mapped resource object. If the resource has
         * not been found, a NoResourceException will be thrown.
         *
         * @param name The name of the resource within the Resources.xml file.
         *
         * @returns The relevant Resource object.
         * 
         * @throws NoResourceException If the resource is not found.
         */
        const Resource_t& get(const std::string& name) const;
    
        //==================== 
        // Methods
        //==================== 
        /**
         * @brief Loads and parses all of the defined resource locations.
         *
         * This method is invoked before the pegasus engine starts. It loads all
         * of the file directories of each resource, which can be retrieved from
         * a defined key. This aids in easier retrieval of resources, instead of
         * relying on file locations, which may change throughout the engines
         * development. If the file cannot be found, an exception will be
         * thrown.
         * 
         * @param filename The file location of the Resources.xml file.
         * 
         * @throws NoResourceException Thrown if the file cannot be found. 
         */
        void load(const std::string& filename);
    };

} // namespace pegasus

#endif//_PEGASUS_RESOURCES_HPP_
