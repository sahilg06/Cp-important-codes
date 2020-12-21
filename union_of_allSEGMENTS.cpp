
ll UnionLength(vpll seg) 
{ 
	ll n = seg.size(); 
	vpll points(n * 2); 
	For(i,0,n-1) 
	{ 
		points[i*2]	 = make_pair(seg[i].first, 0); 
		points[i*2 + 1] = make_pair(seg[i].second, 1); 
	} 
    sort(all(points));
    ll result = 0; 
	// To keep track of counts of current open segments 
	// (Starting point is processed, but ending point is not) 
	ll cnt = 0; 
	For(i,0,n*2-1)
	{ 
		// If there are open points, then we add the difference 
		//between previous and current point. 
		if (cnt) 
			result += (points[i].first - points[i-1].first); 

		// If this is an ending point, reduce count of open points. 
		(points[i].second)? cnt-- : cnt++; 
	} 
	return result; 
} 
/************
Description :
1) Put all the coordinates of all the segments in an auxiliary array points[].
2) Sort it on the value of the coordinates.
3) An additional condition for sorting – if there are equal coordinates, insert the one which is the left coordinate of any segment instead of a right one.
4) Now go through the entire array, with the counter “count” of overlapping segments.
5) If count is greater than zero, then the result is added to the difference between the points[i] – points[i-1].
6) If the current element belongs to the left end, we increase “count”, otherwise reduce it.
************/
