AC_INIT(configRElem, v0.01.085)
AC_ARG_WITH(ElPrefix,
    AC_HELP_STRING(--with-ElPrefix=EL_PREFIX,
        The elemental prefix at the installation),
    UsrPrefix="$withval")

## Check the given prefix:
if test -n "${UsrPrefix}"; then
    if test -f "${UsrPrefix}/conf/ElVars" ; then
        EL_PREFIX="${UsrPrefix}"
        echo "Found Elemental in ${UsrPrefix}"
    else
        AC_MSG_ERROR([Wrong path, ElVars not found in $UsrPrefix ])
    fi
else
  #Checking the common folders
  HIDLOC="/.local"
  for pr in /usr/local /usr/local/El /usr/local/opt/Elemental /opt/El "$HOME/local" "$HOME/local/El" "$HOME$HIDLOC"; do
    if test -f "${pr}/conf/ElVars"; then
      EL_PREFIX="${pr}"
      echo "Found Elemental in ${pr}"
      break
    fi
  done
fi

if test ! -n "${EL_PREFIX}" ; then
   AC_MSG_ERROR([Elemental not found, please specify the prefix of its installation using the flag --with-ElPrefix=/THE/PREFIX])
fi

AC_SUBST(EL_PREFIX)
AC_OUTPUT(src/Makevars)
