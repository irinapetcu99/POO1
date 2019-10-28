#include <iostream>

using namespace std;
class Vector
{ int *v;
  int nr_elem;
  public:
    Vector( int nr_dat, int nr_elem );

    Vector();

    Vector( int nr_elem );

    Vector( const Vector &v1 );

    ~Vector();

    Vector& operator = ( const Vector &v1 );

    Vector& reactualizare( int nr_dat, int nr_elem );

    int suma();

    void maxim();

    Vector& sortare( Vector &v1 );

    Vector operator *( Vector const &v1 );

    int produs_scalar();

    void afisare();
};

Vector :: Vector( int nr_dat, int nr_elem )
    {
        this -> nr_elem = nr_elem;
        v = new int [nr_elem];
        for( int i = 0; i < nr_elem; i++ )
            v[i] = nr_dat;
    }

Vector :: Vector()
    {
        this -> nr_elem = 0;
        v = new int;
    }

Vector :: Vector( int nr_elem )
    {
        this -> nr_elem = nr_elem;
        v = new int[nr_elem];
    }

Vector :: Vector( const Vector &v1 )
    {
        nr_elem = v1.nr_elem;
        v = new int[nr_elem];
        for( int i = 0; i < nr_elem; i++)
            v[i] = v1.v[i];
    }

Vector :: ~Vector()
    {
        delete [] v;
    }

Vector& Vector :: operator = ( const Vector &v1 )
    {
        if( &v1 == this )
        return *this;
        nr_elem = v1.nr_elem;
        delete [] v;
        v = new int[nr_elem];
        for( int i = 0; i < nr_elem; i++)
            v[i] = v1.v[i];
        return *this;
    }

Vector& Vector :: reactualizare( int nr_dat, int nr_elem )
    {
        if( this -> nr_elem != nr_elem )
        { int *temp = new int;
          temp = v;
          v = NULL;
          delete [] v;
          v = new int[nr_elem];
          v = temp;
          delete temp;
          this -> nr_elem = nr_elem;
        }
        for( int i = 0; i < nr_elem; i++)
            v[i] = nr_dat;
        return *this;
    }

int Vector :: suma()
    {
        int sum = 0;
        for( int i = 0; i < nr_elem; i++)
        sum = sum + v[i];
        return sum;
    }

void Vector :: maxim()
    {
        int maxim = v[0], poz = 0;
        for( int i = 1; i < nr_elem; i++)
        if( v[i] > maxim)
            {
                maxim = v[i];
                poz = i;
            }
        cout << "maximul este: "<<maxim<<" si se afla pe pozitia: "<<poz;
    }

Vector& Vector :: sortare( Vector &v1 )
    {
        int i, j, aux;
        for( i = 0; i <= nr_elem - 2; i++ )
        {
            for( j = i + 1; j <= nr_elem - 1; j++ )
            {
                if( v1.v[i] > v1.v[j] )
                {
                  aux = v1.v[i];
                  v1.v[i] = v1.v[j];
                  v1.v[j] = aux;
                }
            }
        }
        return v1;
    }

Vector Vector :: operator *( Vector const &v1 )
    {
        Vector temp;
        temp.v = new int [v1.nr_elem];
        temp.nr_elem = nr_elem;
        for( int i = 0; i < nr_elem; i++)
            temp.v[i] = v[i] * v1.v[i];
        return temp;
    }

int Vector :: produs_scalar()
{
        int prod_scalar=0;
        for( int i = 0; i < nr_elem; i++ )
            prod_scalar = prod_scalar + v[i];
        return prod_scalar;
}

void Vector :: afisare()
    {
      for( int i = 0; i < this -> nr_elem; i++)
            cout << v[i] << " ";
            cout << endl;
    }

int x,n;
int main()
{ cin>>x>>n;
Vector v(x,n);
v.afisare();


}
