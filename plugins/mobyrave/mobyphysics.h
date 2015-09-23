// -*- coding: utf-8 -*-
// Copyright (c) 2015 James Taylor, Rosen Diankov
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.


#include <openrave/plugin.h>
//#include <boost/bind.hpp>

#include "mobyspace.h"

//using namespace Moby;
//using namespace OpenRAVE;
//using namespace std;

class MobyPhysicsEngine : public PhysicsEngineBase
{

   /* inline boost::shared_ptr<MobyPhysicsEngine> shared_physics() {
        return boost::dynamic_pointer_cast<MobyPhysicsEngine>(shared_from_this());
    }
    inline boost::shared_ptr<MobyPhysicsEngine const> shared_physics_const() const {
        return boost::dynamic_pointer_cast<MobyPhysicsEngine const>(shared_from_this());
    }*/

public:
    MobyPhysicsEngine(EnvironmentBasePtr penv, std::istream& ss) : PhysicsEngineBase(penv) 
    {
        // create the simulator reference 
        // TODO: map any environment settings into the simulator settings

        
    }
    virtual ~MobyPhysicsEngine() {}

/*  
    // artifact of BulletPhysics template.  Necessary for Moby?  
    bool SetStaticBodyTransform(ostream& sout, istream& sinput)
    
    {
        return true;
	
    }
*/

    virtual bool InitEnvironment()
    {
        RAVELOG_INFO( "init Moby physics environment\n" );
        //std::cout << "initializing Moby simulation" << std::endl;
        
        return true;
    }

    virtual void DestroyEnvironment()
    {
        RAVELOG_INFO( "destroy Moby physics environment\n" );
       
    }

    virtual bool InitKinBody(KinBodyPtr pbody)
    {
        // TODO: create a body?
       // return !!pinfo;
    }


    virtual void RemoveKinBody(KinBodyPtr pbody)
    {
/*
        std::string id = pbody->GetName();
        Moby::DynamicBodyPtr mobody = _sim->find_dynamic_body( id );
        if( !mobody ) {
          // sanity check here.  Not sure of appropriate OpenRave response,
          // throw or just ignore?
        }
        _sim->remove_dynamic_body( mobody );
*/
    }

    virtual bool SetPhysicsOptions(int physicsoptions)
    {
       // _options = physicsoptions;
        return true;
    }

    virtual int GetPhysicsOptions() const
    {
        //return _options;
    }

    virtual bool SetPhysicsOptions(std::ostream& sout, std::istream& sinput) {
        return false;
    }

    virtual bool SetLinkVelocity(KinBody::LinkPtr plink, const Vector& linearvel, const Vector& angularvel)
    {
       
        return false;
    }
    virtual bool SetLinkVelocities(KinBodyPtr pbody, const std::vector<std::pair<Vector,Vector> >& velocities)
    {
        
        return false;
    }

    virtual bool GetLinkVelocity(KinBody::LinkConstPtr plink, Vector& linearvel, Vector& angularvel)
    {
       
        return true;
    }

    virtual bool GetLinkVelocities(KinBodyConstPtr pbody, std::vector<std::pair<Vector,Vector> >& velocities)
    {
       

        return true;
    }

    virtual bool SetJointVelocity(KinBody::JointPtr pjoint, const std::vector<dReal>& pJointVelocity)
    {
        
        return true;
    }

    virtual bool GetJointVelocity(KinBody::JointConstPtr pjoint, std::vector<dReal>& pJointVelocity)
    {
       
        return true;
    }

      virtual bool AddJointTorque(KinBody::JointPtr pjoint, const std::vector<dReal>& pTorques)
    {
       
       
        return true;
    
    }

    virtual bool SetBodyTorque(KinBody::LinkPtr plink, const Vector& torque, bool bAdd)
    {
       
        return true;
    }

    virtual void SetGravity(const Vector& gravity)
    {     
       // Note: in Moby, gravity is a recurrent force assigned at the
       // individual body level and not through a singular gravity method
       // at the sim level.  The number of recurrent forces is variable,
       // so there may be more than one value in the list for any body.
       // Therefore, must find the correct recurrent force in the set for
       // each body

       // RigidBodyPtr mobody;
       // for each mobody in sim
       //   std::list<Moby::RecurrentForcePtr> forces = mobody->get_recurrent_forces(); 
       //   for each force in forces
       //     if force == _gravity
       //       force = gravity   

       _gravity = gravity;
    }

    virtual Vector GetGravity()
    {
        return _gravity;
    }

    virtual void SimulateStep(dReal fTimeElapsed)
    {
        // step_size = 0.001;
        // int steps = (int)(fTimeElapsed / step_size);
        // for i to steps
        //   _sim->step( steo_size );

        /*
        double dt = 0.001;
        // TODO: compute the number of integration steps in elapsed time
        unsigned steps = 10; // Note: this is arbitrary at this point 
        for( unsigned i = 0; i < steps; i++ ) {
            _sim->step( dt );
        }
        */
    }

private :

    Vector _gravity;
   

};


