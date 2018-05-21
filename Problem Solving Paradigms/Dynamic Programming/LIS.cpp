vll LIS(const vll &elements) {
        auto compare = [&](ll x, ll y) { return elements[x] < elements[y];};
        set <ll, decltype(compare) > s(compare);

        vll previous(elements.size(), -1);

        for(ll i = 0; i < elements.size(); i++) {
            auto it = s.insert(i).first;
            if(it != s.begin()) {
                previous[i] = *prev(it);
            }
            if(*it == i && next(it) != s.end()) {
                s.erase(next(it));
            }
        }

        vll ans;
        ans.push_back(*s.rbegin());
        while(previous[ans.back()] != -1) {
            ans.push_back(previous[ans.back()]);
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
