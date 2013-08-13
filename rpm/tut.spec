Name:    tut
Summary: C++ unit test framework
Version: 0.0.0
Release: 1

License: BSD
Group:	 Development
URL:     http://github.com/nemomobile/tut
Source0: %{name}-%{version}.tar.bz2

%description
TUT is a pure C++ unit test framework. Its name - TUT - stands for 
Template Unit Tests.

%prep
%setup -q -n %{name}-%{version}

%build
./waf configure --prefix=%{_prefix} --version=%{version}
./waf build %{?jobs:-j%jobs}

%install
rm -rf %{buildroot}
./waf install --destdir=%{buildroot}

%clean
rm -rf %{buildroot}

%files
%defattr(-,root,root,-)
%{_includedir}/tut/*.hpp
%{_libdir}/pkgconfig/tut.pc
