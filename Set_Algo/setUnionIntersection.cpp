set<int> setUnion(set<int> s1,set<int> s2){
  set<int> temp = s1;
  for(auto i:s2){
    temp.insert(i);
  }
  return temp;
}

set<int> setIntersection(set<int> s1,set<int> s2){
  set<int> temp;
  auto it1 = s1.begin();
  auto it2 = s2.begin();
  while(it1!=s1.end() && it2!=s2.end()){
    if(*it1>*it2){
        *it2++;
    }
    else if(*it1<*it2){
        *it1++;
    }
    else{
        temp.insert(*it1);
        *it1++;
        *it2++;
    }
  }
  return temp;
}
