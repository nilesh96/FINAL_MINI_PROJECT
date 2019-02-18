/**************************Start*********************************
 * Author - Nilesh kumar
 * Date - 02/02/2019
 * File- Temperature.cpp
****************************************************************/

#include"tempsensor.h"
#include<algorithm>
/*getting all the data from the file and store in the vector*/
bool CTempSensor :: Temp_Get_Data()
{
    ifstream InStream("file.txt");
    if( !InStream )
     {
      cout << "file does not exits" << endl;
      return false;
     }
     else
     {
      cout << "File is open Successfully" << endl; 
     }
     string strLine;
     stringstream ssDivide;
      while( getline ( InStream,strLine))
     {
       ssDivide.clear();
       ssDivide.str(strLine);
       string strOne,strTwo;
          while( getline( ssDivide , strOne , ':' ) && getline( ssDivide , strTwo ) )
           {
	     float m_fTemp = stof(strOne);
	     char m_cState = strTwo[0];
	     m_vect.push_back( make_pair ( m_fTemp , m_cState ) );
            }
       }
    cout << "Data is successfully copied in the data member" << endl; 
    InStream.close();
    return true;
}

/*for display the data of the vector or file*/
void CTempSensor :: Temp_Display_Data( void )
{
    cout << "data of vector" << endl;
    for( unsigned int nVar = 0; nVar < m_vect.size() ; nVar++ )
    {
      cout << m_vect[nVar].first << " " << m_vect[nVar].second << endl;
    }
}

/* Attach the observer and store in the vector*/
int CTempSensor:: Temp_Attach(IObserver * pIobsAttach)
{
    m_observers.push_back(pIobsAttach);
    return 0;
}

/*To remove the observer first find the observer and then erase it*/
void CTempSensor:: Temp_Detach(IObserver *observer)
{
    auto itr = find(m_observers.begin(),m_observers.end(),observer);

    if(itr != m_observers.end())
    {
      m_observers.erase(itr);
    }

}

/*Notify to all the observer for temperature data*/
void CTempSensor :: Temp_Notify( void )
{
    for(IObserver  *observer : m_observers)
    {
       observer->Moniter_Update(m_fTemp,m_cState);
	  
    }
}

/* After getting data from the file and update the data one by one */
void CTempSensor::Temp_Set_Data( void )
{
    for(unsigned int  i = 0; i < m_vect.size() ; i++)
     { 
       m_fTemp = m_vect[i].first;
       m_cState = m_vect[i].second;
       Temp_Notify();
     }
}
