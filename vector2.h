template <typename T>
struct vector
{
    T x,y;

    vector<T>& operator+=(vector<T> const& v) {
        x += v.x; y+= v.y;
        return *this;
    }
    vector<T>& operator-=(vector<T> const&v) {
        x -= v.x; y -= v.y;
        return *this;
    }
    vector<T>& operator*=(const T k) {
        x *= k; y *= k;
        return *this;
    }
    vector<T>& operator/=(const T k) {
        x /= k; y /= k;
        return *this;
    }
};
template <typename T>
    double dot(vector<T> const &a, vector<T> const &b){
        return a.x*b.x + a.y*b.y;
    }
template <typename T>
    double length(vector<T> const &a){
        return sqrt(a.x*a.x + a.y*a.y);
    }
template <typename T>
    vector<T> normalize(vector<T> &a){
        return a /= length(a);
    }
template <typename T>
    double sq(const T x){
        return x*x;
    }
template <typename T>
    double sqlength(vector<T> const &a){
        return sq(sqrt(a.x*a.x + a.y*a.y));
    }   
template <typename T>
    std::istream& operator>>( std::istream&i , vector<T>&v ){
    i >> v.x;
    i >> v.y;
    return i;
}
template <typename T>
    std::ostream& operator<<( std::ostream& o, vector<T> const& v ){
    o << v.x << " " << v.y;
    return o;
}

