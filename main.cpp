#include <iostream>

using namespace std;

class Citire_si_Afisare;

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

    Vector& sortare();

    int operator *( Vector const &v1 );

    friend ostream& operator << ( ostream&, Vector& );

    friend istream& operator >> ( istream&, Vector& );

    friend class Citire_si_Afisare;
};

class Citire_si_Afisare
{
  int n;
  Vector *ob;
  public:

  Citire_si_Afisare() ///constructor fara parametri
  {
      cout << "dati nr de obiecte de citit:"<<endl;
      cin >> this -> n;
      ob = new Vector[n];
  }

  void citire_si_afisare()
  {
      for( int i = 0; i < n; i++ )
      {
      cin >> ob[i];
      }
      cout << "obiectele sunt:" << endl;
      for( int i = 0; i < n; i++ )
          cout << ob[i];
  }
  ~Citire_si_Afisare() ///destructor
  {
      delete [] ob;
  }
};


///constructor pentru initializarea cu un numar dat pe toate componentele
Vector :: Vector( int nr_dat, int nr_elem )
    {
        cout << "obiectul a fost creat si are " << nr_elem << " elemente,toate fiind " << nr_dat << endl;
        this -> nr_elem = nr_elem;
        v = new int [nr_elem];
        for( int i = 0; i < nr_elem; i++ )
            v[i] = nr_dat;
    }

///constructor de initializare fara parametri
Vector :: Vector()
    {
        cout << "obiectul a fost creat si este null" << endl;
        this -> nr_elem = 0;
        v = new int;
    }

///constructor de initializare cu parametru
Vector :: Vector( int nr_elem )
    {
        cout << "obiectul a fost creat si are " << nr_elem << " elemente" << endl;
        this -> nr_elem = nr_elem;
        v = new int[nr_elem];
    }

///constructor de copiere
Vector :: Vector( const Vector &v1 )
    {
        cout << "obiectul a fost creat si este o copie a unui alt vector" << endl;
        nr_elem = v1.nr_elem;
        v = new int[nr_elem];
        for( int i = 0; i < nr_elem; i++)
            v[i] = v1.v[i];
    }

///destructor
Vector :: ~Vector()
    {
        cout << "obiectul a fost distrus" << endl;
        delete [] v;
    }

///metoda-operator de atribuire =
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

/**metoda pentru reactualizarea numarului de componente si
initializarea componentelor cu un numar dat*/
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

///metoda pentru calculul sumei tuturor elementelor vectorului
int Vector :: suma()
    {
        int sum = 0;
        for( int i = 0; i < nr_elem; i++)
        sum = sum + v[i];
        return sum;
    }

///metoda pentru gasirea maximului si a pozitiei lui
void Vector :: maxim()
    {
        int maxim = v[0], poz = 0;
        for( int i = 1; i < nr_elem; i++)
        if( v[i] > maxim)
            {
                maxim = v[i];
                poz = i;
            }
        cout << "maximul este: " << maxim << " si se afla pe pozitia: " << poz + 1 << endl;
    }

///metoda pentru sortarea crescatoare a vectorului
Vector& Vector :: sortare()
    {
        int i, j, aux;
        for( i = 0; i <= nr_elem - 2; i++ )
        {
            for( j = i + 1; j <= nr_elem - 1; j++ )
            {
                if( v[i] > v[j] )
                {
                  aux = v[i];
                  v[i] = v[j];
                  v[j] = aux;
                }
            }
        }
        return *this;
    }

///metoda-operator * pentru inmultirea a 2 vectori
int Vector :: operator *( Vector const &v1 )
    {
        cout << "un obiect temporar va fi creat , in care va fi retinut produsul celor 2 vectori :" << endl;
        Vector temp;
        temp.v = new int [v1.nr_elem];
        temp.nr_elem = nr_elem;
        for( int i = 0; i < nr_elem; i++)
            temp.v[i] = v[i] * v1.v[i];


        return temp.suma();
    }

///metoda de afisare a unui obiect
ostream& operator << ( ostream & out, Vector &v )
{
    cout << "numarul elementelor:" << endl;
        out<< v.nr_elem << endl;
    cout << "elementele:" << endl;
    for( int i = 0; i < v.nr_elem; i++ )
        out << v.v[i] << " ";
        out << endl;
    return out;
}

///metoda de citire a unui obiect
istream& operator >> ( istream& in, Vector &v )
{
    cout << "dati numarul componentelor vectorului:" << endl;
    cin >> v.nr_elem;
    int *temp = new int;
    temp = v.v;
    v.v= NULL;
    delete [] v.v;
    v.v= new int[v.nr_elem];
    v.v = temp;
    delete temp;
    for ( int i = 0; i < v.nr_elem; i++ )
    {
        cout << "introduceti elementul " << i << " al vectorului:" << endl;
        in >> v.v[i];
    }
    return in;
}

int main()
{
    int nr_comp,val,optiune;
    cout << "optiunea:" << endl;
    cout << "1 - initializarea cu un numar dat pe toate componentele" << endl;
    cout << "2 - crearea obiectului fara numar de componente" << endl;
    cout << "3 - crearea obiectului cu numar de componente" << endl;
    cout << "4 - crearea unei copii(constructor de copiere)" << endl;
    cout << "5 - modificarea unui obiect prin supraincarcarea operatorului =" << endl;
    cout << "6 - reactualizarea numarului de componente ale unui obiect" << endl;
    cout << "7 - suma elementelor unui vector" << endl;
    cout << "8 - maximul si pozitia maximului" << endl;
    cout << "9 - sortarea unui vector" << endl;
    cout << "10 - produsul scalar a 2 vectori" << endl;
    cout << "11 - citirea si afisarea a n obiecte" << endl;
    cin >> optiune;
    switch( optiune )
    {
        case 1:
    {
        cout << "dati numarul componentelor si valoarea cu care sa fie initializate:" << endl;
        cin >> nr_comp >> val;
        Vector v( val, nr_comp );
        cout << v;
        break;
    }
        case 2:
    {
        Vector v;
        cout << v;
        break;

    }
        case 3:
    {
        cout << "dati numarul de componente ale obiectului:" << endl;
        cin >> nr_comp;
        Vector v( nr_comp );
        cout << v;
        break;
    }
        case 4:
    {
        cout << "dati numarul de elemente si valoaea acestora:" << endl;
        cin >> nr_comp >> val;
        Vector v( val, nr_comp );
        Vector v1( v );
        cout << v1;
        break;

    }
        case 5:
    {
        cout << "dati numarul de elemente ale primului vector si valoarea acestora:" << endl;
        cin >> nr_comp >> val;
        Vector v( val, nr_comp );
        cout << "dati numarul de componente ale celui de-al 2 lea vector si valoarea lor:" << endl;
        cin >> nr_comp >> val;
        Vector v1( val, nr_comp );
        cout << "vectorul initial este:" << endl;
        cout << v1;
        cout << "vectorul final este:" << endl;
        v1 = v;
        cout << v1;
        break;
    }
        case 6:
    {
        cout << "dati numarul de componente ale vectorului si valoarea acestora:" << endl;
        cin >> nr_comp >> val;
        Vector v( val,nr_comp );
        cout << "vectorul initial este:" << endl;
        cout << v;
        cout << "dati noul numar de componente si valoarea lor:" << endl;
        cin >> nr_comp >> val;
        v.reactualizare( val, nr_comp );
        cout << "vectorul final este:" << endl;
        cout << v;
        break;
    }
        case 7:
    {
        Vector v;
        cin >> v;
        cout << "suma elementelor vectorului este " << v.suma() << endl;
        break;
    }
        case 8:
    {
        Vector v;
        cin >> v;
        cout << "vectorul este:" << endl;
        cout << v;
        v.maxim();
        break;
    }
        case 9:
    {
        Vector v;
        cin >> v;
        cout << "vectorul initial este:" << endl;
        cout << v;
        cout << "vectorul sortat este:" << endl;
        v.sortare();
        cout << v;
        break;

    }
        case 10:
    {
        Vector v;
        cin >> v;
        cout << v;
        Vector v1;
        cout << "al doilea vector trebuie sa aiba acelasi numar de elemente!" << endl;
        cin >> v1;
        cout << v1;
        cout << "produsul scalar este: " << v * v1 << endl;
        break;
    }
        case 11:
    {
        Citire_si_Afisare vct_obiecte;
        vct_obiecte.citire_si_afisare();
    }
    }
}
